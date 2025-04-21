export module Scanner;

#include <string>

enum class TokenType {
  // Single-character tokens.
  LEFT_PAREN, RIGHT_PAREN,
  LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS,
  SEMICOLON, SLASH, STAR,
  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,
  // Literals.
  IDENTIFIER, STRING, NUMBER,
  // Keywords.
  AND, CLASS, ELSE, FALSE,
  FOR, FUN, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS,
  TRUE, VAR, WHILE,

  ERROR, T_EOF
};

struct Token {
  TokenType type;
  std::string::const_iterator m_start;
  unsigned int length;
  unsigned int line;
};


class Scanner {
  std::string::const_iterator m_start;
  std::string::const_iterator m_current;
  unsigned int m_line = 1;

  char advance();
  char peek();
  char peekNext();

  Token makeToken(TokenType type);
  Token makeErrorToken(std::string const& message);
  bool match(char expected);
  void skipWhitespace();
  Token string();
  Token number();
  Token identifier();
  TokenType identifierType();
  TokenType checkKeyword(int m_start, int length, std::string_view const rest, TokenType type);

public:
  Scanner(std::string const& source);

  Token scanToken();
};