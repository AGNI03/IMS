#pragma once

#include <string>
#include <memory>


struct Result; // Forward declaration

class AuthService {
public:
	AuthService() = delete;
	 static Result login(const std::string& inputID, std::string& inputPwd);
};