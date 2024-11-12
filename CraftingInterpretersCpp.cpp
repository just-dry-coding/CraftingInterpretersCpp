import common;
import chunk;
import debug;

int main() {
	auto chunks = Chunk{ OpCode::OP_RETURN };
	disassembleChunk(chunks, "test chunk");
}