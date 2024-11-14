import Debug;
import Chunk;
import Common;

#include <string>
#include <print>


void disassembleChunk(Chunk const& chunk, std::string const& name)
{
	std::print("== {} ==\n", name);
	for (unsigned int offset = 0; offset < chunk.size(); ++offset) {
		std::print("{}\t", offset);
		disassembleInstruction(chunk, offset);
	}
}

void disassembleInstruction(Chunk const& chunk, unsigned int offset)
{
	auto const instruction = chunk[offset];
	switch (instruction.opCode) {
	case OpCode::OP_CONSTANT:
		auto constantInstruction = static_cast<ConstantInstruction>(instruction);
		return std::print("OP_CONSTANT {}\n", chunk.getConstant(constantInstruction.constantIndex));
	case OpCode::OP_RETURN:
		return std::print("OP_RETURN\n");
	default:
		return std::print("unknow code\n");
	}
}
