import debug;
import chunk;
import common;

#include <string>
#include <print>

int simpleInstruction(std::string const&, int);

void disassembleChunk(Chunk const& chunk, std::string const& name)
{
	std::print("== {} ==\n", name);
	for (unsigned int offset = 0; offset < chunk.size();) {
		offset = disassembleInstruction(chunk[offset], offset);
	}
}

int disassembleInstruction(Instruction const& instruction, int offset)
{
	std::print("{}\t", offset);
	switch (instruction.opCode) {
	case OpCode::OP_RETURN:
		return simpleInstruction("OP_RETURN", offset);
	default:
		std::print("unknow code");
		return offset + 1;
	}

}

int simpleInstruction(std::string const& name, int offset) {
	std::print("{}\n", name);
	return offset + 1;
}
