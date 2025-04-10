import Chunk;
import Common;
import Value;
import Stack;

#include <cstdint>
#include <memory>
#include <iterator>
#include <vector>

export module Vm;

export class Vm {
public:
	Chunk const* chunk;
  size_t ip;
  Stack stack;
};

export enum class InterpretResult {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
};

export InterpretResult interpret(Chunk* chunk);