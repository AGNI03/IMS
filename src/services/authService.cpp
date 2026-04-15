#include "authService.hpp"

#include "models/User.hpp"
#include "database/UserRepo.hpp"

#include "bcrypt.h"

#include <stdexcept>
#include <iostream>

Result<User> AuthService::login(const std::string& inputID, const std::string& inputPwd) {
	try {
		auto user = UserRepo::getUserById(inputID);
		if (user._id.empty()) return { false, {}, ErrorType::NOT_FOUND_ERROR, "User not found" };
		if (!bcrypt::validatePassword(inputPwd, user.password_hash)) return { false, {}, ErrorType::NOT_FOUND_ERROR, "User not found"};

		return { true, user, ErrorType::NONE, "" };
		
	}
	catch (const std::exception& e) {
		return { false, {}, ErrorType::INTERNAL_ERROR, e.what() };
	}
}
