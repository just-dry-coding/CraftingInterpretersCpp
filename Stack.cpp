import Stack;

void Stack::reset()
{
  m_stackTop = m_stack.data();
}

void Stack::push(Value value)
{
  *m_stackTop = value;
  m_stackTop++;
}

Value Stack::pop()
{
  m_stackTop--;
  return *m_stackTop;
}

Value const* Stack::begin() const
{
  return m_stack.data();
}

Value const* Stack::end() const
{
  return m_stackTop;
}