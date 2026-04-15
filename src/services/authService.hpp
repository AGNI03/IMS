#pragma once

#include <string>

#include "Result.hpp"
#include "models/User.hpp"

class AuthService {
public:
	AuthService() = delete;
	 static Result<User> login(const std::string& inputID, const std::string& inputPwd);
};