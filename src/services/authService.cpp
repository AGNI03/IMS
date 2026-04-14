#include "authService.hpp"

#include "User.hpp"
#include "userRepo.hpp"

#include "bcrypt.h"

#include <stdexcept>
#include <iostream>

User AuthService::login(const std::string& inputID, std::string& inputPwd) {
	auto user = UserRepo::getUserById(inputID);
	if (user._id.empty()) {
		std::cout << "LOGIN FAILED: Received empty user for ID: " << inputID << std::endl;
		throw std::runtime_error("user not found");
	}
	if (!bcrypt::validatePassword(inputPwd, user.password_hash)) {
		throw std::runtime_error("UserID or Password is incorrect");
	}

	return user;
}
