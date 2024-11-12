import chunk;
#include <string_view>


export module debug;

export void disassembleChunk(Chunk const& chunk, std::string_view const & name);
export int disassembleInstruction(Chunk const& chunk, int offset);

