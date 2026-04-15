#include "AuthController.hpp"
#include "models/User.hpp"
#include "services/authService.hpp"
#include "Result.hpp"
#include "HandleBadRequest.hpp"

using namespace api::v1;

void Auth::login(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback) const {

	// check if the request body is a valid JSON object
	auto jsonReq = req->getJsonObject();
	if(handleBadRequest(!jsonReq, "Invalid JSON body", callback)) return;
	
	if(handleBadRequest(!jsonReq->isMember("userId") || !(*jsonReq)["userId"].isString(), "Invalid 'userId' or 'password'", callback)) return;
	if(handleBadRequest(!jsonReq->isMember("password") || !(*jsonReq)["password"].isString(), "Invalid 'userId' or 'password'", callback)) return;

	// parse the JSON body
	std::string userId = (*jsonReq)["userId"].asString();
	std::string password = (*jsonReq)["password"].asString();

	// login the user
	auto result = AuthService::login(userId, password);
	

	// create a JSON response

}