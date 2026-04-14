#pragma once

#include <string>
#include "ErrorType.hpp"

template<typename T>
struct Result {
	bool success;
	T data;
	ErrorType error;
	std::string message;
};