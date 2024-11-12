import chunk;
#include <string>


export module debug;

export void disassembleChunk(Chunk const& chunk, std::string const & name);
export int disassembleInstruction(OpCode chunk, int offset);

