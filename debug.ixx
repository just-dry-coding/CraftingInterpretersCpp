import Chunk;
import Common;
import Value;
import Stack;

#include <string>

export module Debug;

export void disassembleChunk(Chunk const& chunk, std::string const & name);
export void disassembleInstruction(Instruction const* instruction, Chunk const& chunk);
export void disassembleStack(Stack const& stack);
