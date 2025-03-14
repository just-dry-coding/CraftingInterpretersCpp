import Common;
import Chunk;
import Debug;
import Vm;

int main() {
	auto chunk = Chunk{};
	chunk.push_back(OpCode::OP_CONSTANT, 1.2, 123);
	chunk.push_back(OpCode::OP_RETURN, 123);
	disassembleChunk(chunk, "test chunk");
	interpret(&chunk);
}