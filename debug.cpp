import debug;
import chunk;
import common;

#include <string_view>
#include <print>

void disassembleChunk(Chunk const& chunk, std::string_view const& name)
{
	std::print("== {} ==\n", name);
	for (unsigned int offset = 0; offset < chunk.size();) {
		offset = disassembleInstruction(chunk[offset], offset);
	}
}

int disassembleInstruction(OpCode code, int offset)
{
	std::print("{}", offset);
	switch (code) {
	case OpCode::OP_RETURN:
		return simpleInstruction("OP_RETURN", offset);
	default:
		std::print("Unknown opcode {}\n", code);
		return offset + 1;
	}
}

int simpleInstruction(std::string_view const& name, int offset) {
	std::print("{}", name);
	return offset + 1;
}
