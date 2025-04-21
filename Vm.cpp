import Vm;
import Value;
import Debug;
import Common;

#include <print>
#include <functional>

Vm vm;

Instruction const * readByte() {
  return vm.chunk->getInstruction(vm.ip++);
}

Value readConstant(Instruction const* instruction) {
  return vm.chunk->getConstant(static_cast<ConstantInstruction const*>(instruction)->constantIndex);
}

void binaryOperation(auto op) {
  auto a = vm.stack.pop();
  auto b = vm.stack.pop();
  vm.stack.push(op(a,b));
}

InterpretResult run() {
  for (;;) {
    auto instruction = readByte();
    disassembleInstruction(instruction, *vm.chunk);
    switch (instruction->opCode) {
    case OpCode::CONSTANT: {
      Value const constant = readConstant(instruction);
      vm.stack.push(constant);
      break;
    }
    case OpCode::ADD: {
      binaryOperation(std::plus());
      break;
    }
    case OpCode::SUBTRACT: {
      binaryOperation(std::minus());
      break;
    }
    case OpCode::MULTIPLY: {
      binaryOperation(std::multiplies());
      break;
    }
    case OpCode::DIVIDE: {
      binaryOperation(std::divides());
      break;
    }
    case OpCode::NEGATE: {
      vm.stack.push(-vm.stack.pop());
      break;
    }
    case OpCode::RETURN: {
        std::print("{}", vm.stack.pop());
        return InterpretResult::OK;
      }
    }
  }
}

InterpretResult interpret(std::string const& source) {
  Chunk chunk;

  if (!compile(source, chunk))
    return InterpretResult::COMPILE_ERROR;

  vm.chunk = &chunk;
  vm.ip = chunk.begin();

  InterpretResult resutl = run();

  return InterpretResult::OK;
}