#include <vector>
#include <variant>
import value;
import common;

export module chunk;

export struct Instruction {
	OpCode opCode;
};

export struct SimpleInstruction : Instruction{
};

export struct ConstantInstruction : Instruction{
	uint8_t constantIndex;
};


export class Chunk : public std::vector<Instruction> {
	ValueArr m_constants;
public:
	Value getConstant(size_t const index) const {
		return m_constants[index];
	}

	uint8_t addConstant(Value value) {
		m_constants.push_back(value);
		return static_cast<uint8_t>(m_constants.size()) - 1;
	}
};