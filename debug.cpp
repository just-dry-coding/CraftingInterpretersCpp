import Debug;
import Chunk;
import Common;
import Stack;

#include <string>
#include <glog/logging.h>


void disassembleChunk(Chunk const& chunk, std::string const& name)
{
	LOG(INFO) << "==" << name << "==\n";
	for (unsigned int offset = 0; offset < chunk.size(); ++offset) {
		LOG(INFO) << offset << "\t";
		disassembleInstruction(chunk[offset], chunk);
	}
}

void disassembleInstruction(Instruction const* instruction, Chunk const& chunk)
{
	switch (instruction->opCode) {
	case OpCode::CONSTANT: {
		auto constantInstruction = static_cast<ConstantInstruction const*>(instruction);
		LOG(INFO) << "OP_CONSTANT" << chunk.getConstant(constantInstruction->constantIndex) << "\n";
		return;
	}
	case OpCode::ADD: {
		LOG(INFO) << "OP_ADD\n";
		return;
	}
	case OpCode::SUBTRACT: {
		LOG(INFO) << "OP_SUBTRACT\n";
		return;
	}
	case OpCode::MULTIPLY: {
		LOG(INFO) << "OP_MULTIPLY\n";
		return;
	}
	case OpCode::DIVIDE: {
		LOG(INFO) << "OP_DIVIDE\n";
		return;
	}
	case OpCode::NEGATE: {
		LOG(INFO) << "OP_NEGATE\n";
		return;
	}
	case OpCode::RETURN:
		LOG(INFO) << "OP_RETURN\n";
		return;
	default:
		LOG(INFO) << "unknow code\n";
		return;
	}
}

void disassembleStack(Stack const& stack)
{
	LOG(INFO) << "         ";
	for (auto it = stack.begin(); it != stack.end(); it++)
		LOG(INFO) << '[' << *it << ']';
	LOG(INFO) << '\n';
}

