#include <iostream>

export module Common;

export enum class OpCode : uint8_t {
	OP_CONSTANT = 0,
	OP_RETURN = 1,
};