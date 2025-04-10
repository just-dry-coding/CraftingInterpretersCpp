#include <iostream>

export module Common;

export enum class OpCode : uint8_t {
	CONSTANT = 0,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	NEGATE,
	RETURN,
};