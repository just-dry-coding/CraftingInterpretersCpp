import chunk;
import common;
#include <string>


export module debug;

export void disassembleChunk(Chunk const& chunk, std::string const & name);
export void disassembleInstruction(Chunk const& chunk, unsigned int offset);

