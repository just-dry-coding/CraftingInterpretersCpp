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


int disassembleInstruction(OpCode code, int offset)
{
	std::print("{}\t", offset);
	switch (code) {
	case OpCode::OP_RETURN:
		return simpleInstruction("OP_RETURN", offset);
	}
}

int simpleInstruction(std::string const& name, int offset) {
	std::print("{}", name);
	return offset + 1;
}
