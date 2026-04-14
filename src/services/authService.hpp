#pragma once

#include <string>
#include <memory>


class User; // Forward declaration

class AuthService {
public:
	AuthService() = delete;
	 static User login(const std::string& inputID, std::string& inputPwd);
};