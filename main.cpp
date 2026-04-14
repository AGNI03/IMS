#include <drogon/drogon.h>
#include "EnvLoader.hpp"

int main(){
	EnvLoader::load(".env");
    drogon::app().loadConfigFile("drogonConfig.json").run();
    return 0;
}
