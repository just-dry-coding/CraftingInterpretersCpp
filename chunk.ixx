#include <vector>
#include <map>

import Value;
import Common;
import RunLengthEncoding;

export module Chunk;

export struct Instruction {
	OpCode opCode;
};

export struct SimpleInstruction : Instruction{
};

export struct ConstantInstruction : Instruction{
	uint8_t constantIndex;
};


export class Chunk {
	std::vector<Instruction> m_instructions;
	ValueArr m_constants;
	RunLengthEncoding<size_t> m_lineInfo;

public:
	size_t size() const {
		return m_instructions.size();
	}

	Instruction& operator[](size_t idx) {
		return m_instructions[idx];
	}
	Instruction const& operator[](size_t idx) const {
		return m_instructions[idx];
	}

	void push_back(OpCode opCode, size_t lineInfo) {
		m_lineInfo.add(lineInfo);
		m_instructions.push_back(SimpleInstruction{ opCode });
		
	}
	void push_back(OpCode opCode, Value constant, size_t lineInfo) {
		m_lineInfo.add(lineInfo);
		auto const constantIndex = addConstant(constant);
		m_instructions.push_back(ConstantInstruction{ opCode, constantIndex });
	}
	Value getConstant(size_t const index) const {
		return m_constants[index];
	}
	size_t getLineInfo(size_t instructionIndex) const {
		return m_lineInfo.get(instructionIndex);
	}

private:
	uint8_t addConstant(Value value) {
		m_constants.push_back(value);
		return static_cast<uint8_t>(m_constants.size()) - 1;
	}

};