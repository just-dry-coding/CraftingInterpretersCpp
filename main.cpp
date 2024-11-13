import common;
import chunk;
import debug;

int main() {
	auto chunks = Chunk{};
	chunks.push_back(SimpleInstruction{ OpCode::OP_RETURN, 123 });
	auto constant = chunks.addConstant(1.2);
	chunks.push_back(ConstantInstruction{ OpCode::OP_CONSTANT, 123, constant });
	disassembleChunk(chunks, "test chunk");
}