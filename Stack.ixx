import Value;

#include <array>

export module Stack;

constexpr size_t STACK_MAX = 256;

// using own stack class to comply with book and allow debug print
export class Stack
{
  std::array<Value, STACK_MAX> m_stack;
  Value* m_stackTop = m_stack.data();
public:
  void reset();
  void push(Value value);
  Value pop();
  Value const* begin() const;
  Value const* end() const;
};