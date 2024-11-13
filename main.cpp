import common;
import chunk;
import debug;

int main() {
	auto chunks = Chunk{};
	chunks.push_back(SimpleInstruction{ OpCode::OP_RETURN });
	auto constant = chunks.addConstant(1.2);
	chunks.push_back(ConstantInstruction{ OpCode::OP_CONSTANT, constant });
	disassembleChunk(chunks, "test chunk");
}