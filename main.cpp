import common;
import chunk;
import debug;

int main() {
	auto chunks = Chunk{};
	chunks.push_back(OpCode::OP_RETURN, 123);
	chunks.push_back(OpCode::OP_CONSTANT, 1.2, 123);
	disassembleChunk(chunks, "test chunk");
}