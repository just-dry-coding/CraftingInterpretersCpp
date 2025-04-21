import Chunk;
import Common;
import Value;
import Stack;

#include <cstdint>
#include <memory>
#include <iterator>
#include <vector>
#include <string>

export module Vm;

export class Vm {
public:
	Chunk const* chunk;
  std::vector<std::unique_ptr<Instruction>>::const_iterator ip;
  Stack stack;
};

export enum class InterpretResult {
  OK,
  COMPILE_ERROR,
  RUNTIME_ERROR
};

export InterpretResult interpret(std::string const& source);