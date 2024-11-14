import Chunk;
import Common;
#include <string>


export module Debug;

export void disassembleChunk(Chunk const& chunk, std::string const & name);
export void disassembleInstruction(Chunk const& chunk, unsigned int offset);

