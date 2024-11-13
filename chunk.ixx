#include <vector>
import common;
import value;

export module chunk;


export class Chunk : public std::vector<OpCode> {
	ValueArr constants;
};