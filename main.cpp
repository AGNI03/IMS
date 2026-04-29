#include <drogon/drogon.h>

#include "database/userRepo.hpp"
#include "EnvLoader.hpp"

#include <fstream>

int main(){


	EnvLoader::load("../.env");


	UserRepo::init();

	std::cout << "Starting server..." << std::endl;
    drogon::app().loadConfigFile("../drogonConfig.json").run();
	//drogon::app().addListener("127.0.0.1", 8848).run();
	std::cout << "Server stopped." << std::endl;
	

    return 0;
}
