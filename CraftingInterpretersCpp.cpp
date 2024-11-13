import common;
import chunk;
import debug;

int main() {
	auto chunks = Chunk{};
	chunks.push_back(OpCode::OP_RETURN);
	disassembleChunk(chunks, "test chunk");
}