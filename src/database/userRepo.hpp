# pragma once

#include <mysqlx/xdevapi.h>
#include <memory>


class User;

class UserRepo {
	static std::unique_ptr<mysqlx::Client> client;
	
private:
	UserRepo(const std::string& uri);
	UserRepo(const UserRepo&) = delete;
	UserRepo& operator=(const UserRepo&) = delete;

public :
	static UserRepo& getInstance();
	static void init();

	static User getUserById(const std::string& userId);

};