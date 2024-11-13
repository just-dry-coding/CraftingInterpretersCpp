import debug;
import chunk;
import common;

#include <string>
#include <print>

int simpleInstruction(std::string const&, int);

void disassembleChunk(Chunk const& chunk, std::string const& name)
{
	std::print("== {} ==\n", name);
	for (unsigned int offset = 0; offset < chunk.size(); ++offset) {
		std::print("{}\t", offset);
		disassembleInstruction(chunk[offset], offset);
	}
}

void disassembleInstruction(Instruction const& instruction)
{
	switch (instruction.opCode) {
	case OpCode::OP_RETURN:
		std::print("OP_RETURN");
	default:
		std::print("unknow code");
	}
}
