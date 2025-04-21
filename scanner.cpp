import Scanner;

namespace {
  bool isEndToken(char c) {
    return c == '\0';
  }
}

Scanner::Scanner(std::string const& source) {
  m_start = source.begin();
  m_current = source.begin();
}

Token Scanner::scanToken()
{
  skipWhitespace();
  m_start = m_current;

  if (isEndToken(*m_current))
    return makeToken(TokenType::T_EOF);

  char c = advance();

  if (isalpha(c))
    return identifier(c);

  if (isdigit(c))
    return number();

  switch (c) {
    case '(': return makeToken(TokenType::LEFT_PAREN);
    case ')': return makeToken(TokenType::RIGHT_PAREN);
    case '{': return makeToken(TokenType::LEFT_BRACE);
    case '}': return makeToken(TokenType::RIGHT_BRACE);
    case ';': return makeToken(TokenType::SEMICOLON);
    case ',': return makeToken(TokenType::COMMA);
    case '.': return makeToken(TokenType::DOT);
    case '-': return makeToken(TokenType::MINUS);
    case '+': return makeToken(TokenType::PLUS);
    case '/': return makeToken(TokenType::SLASH);
    case '*': return makeToken(TokenType::STAR);
    case '!':
      return makeToken(
          match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
    case '=':
      return makeToken(
          match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
    case '<':
      return makeToken(
          match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
    case '>':
      return makeToken(
          match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
    case '"': return string();
  }

  return makeErrorToken("Unexpected character");
}

char Scanner::advance()
{
  return *m_current++;
}

char Scanner::peek()
{
  return *m_current;
}

char Scanner::peekNext()
{
  if (isEndToken(*m_current))
    return '\0';
  return m_current[1];
}

Token Scanner::makeToken(TokenType type)
{
  return {.type = type, .m_start = m_start, .length = static_cast<unsigned int>(m_current - m_start), .line = m_line};
}

Token Scanner::makeErrorToken(std::string const& message)
{
  // only called with lexeme so message stays valid
  return {.type = TokenType::ERROR, .m_start = message.begin(), .length = static_cast<unsigned int>(message.size()), .line = m_line};
}

bool Scanner::match(char expected)
{
  if (isEndToken(*m_current))
    return false;
  if (*m_current != expected)
    return false;
  m_current++;
  return true;
}

void Scanner::skipWhitespace()
{
  for (;;) {
    char c = peek();
    switch (c) {
      case ' ':
      case '\r':
      case '\t':
        advance();
        break;
      case '\n':
        m_line++;
        advance();
        break;
      case '/':
        if (peekNext() == '/') {
          // A comment goes until the end of the line.
          while (peek() != '\n' && !isEndToken(*m_current)) advance();
        } else {
          return;
        }
        break;
      default:
        return;
    }
  }
}

Token Scanner::string()
{
  while (peek() != '"' && !isEndToken(*m_current)) {
    if (peek() == '\n')
      m_line++;
    advance();
  }

  if (isEndToken(*m_current)) 
    return makeErrorToken("Unterminated string.");

  // The closing quote.
  advance();
  return makeToken(TokenType::STRING);
}

Token Scanner::number()
{
  while (isdigit(peek()))
    advance();

  // Look for a fractional part.
  if (peek() == '.' && isdigit(peekNext())) {
    advance();

    while (isdigit(peek()))
      advance();
  }

  return makeToken(TokenType::NUMBER);
}

Token Scanner::identifier()
{
  while (isalpha(peek()) || isdigit(peek()))
    advance();
  return makeToken(identifierType());
}

TokenType Scanner::identifierType() {
  switch (m_start[0]) {
    case 'a': return checkKeyword(1, 2, "nd", TokenType::AND);
    case 'c': return checkKeyword(1, 4, "lass", TokenType::CLASS);
    case 'e': return checkKeyword(1, 3, "lse", TokenType::ELSE);
    case 'f':
    if (m_current - m_start > 1) {
      switch (m_start[1]) {
        case 'a': return checkKeyword(2, 3, "lse", TokenType::FALSE);
        case 'o': return checkKeyword(2, 1, "r", TokenType::FOR);
        case 'u': return checkKeyword(2, 1, "n", TokenType::FUN);
      }
    }
    break;
    case 'i': return checkKeyword(1, 1, "f", TokenType::IF);
    case 'n': return checkKeyword(1, 2, "il", TokenType::NIL);
    case 'o': return checkKeyword(1, 1, "r", TokenType::OR);
    case 'p': return checkKeyword(1, 4, "rint", TokenType::PRINT);
    case 'r': return checkKeyword(1, 5, "eturn", TokenType::RETURN);
    case 's': return checkKeyword(1, 4, "uper", TokenType::SUPER);
    case 't':
    if (m_current - m_start > 1) {
      switch (m_start[1]) {
        case 'h': return checkKeyword(2, 2, "is", TokenType::THIS);
        case 'r': return checkKeyword(2, 2, "ue", TokenType::TRUE);
      }
    }
    break;
    case 'v': return checkKeyword(1, 2, "ar", TokenType::VAR);
    case 'w': return checkKeyword(1, 4, "hile", TokenType::WHILE);
  }

  return TokenType::IDENTIFIER;
}

TokenType Scanner::checkKeyword(int start, int length, std::string_view const rest, TokenType type) {
  auto currentTokenLength = std::distance(m_start, m_current);
  auto currentTokenRestBegin = m_start + start;
    
  if (currentTokenLength = start + length && std::equal(currentTokenRestBegin, currentTokenRestBegin + length, rest.begin(), rest.end()))
      return type;

  return TokenType::IDENTIFIER;
}
