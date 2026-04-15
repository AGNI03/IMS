#include "AuthController.hpp"
#include "models/User.hpp"
#include "services/authService.hpp"
#include "Result.hpp"
#include "HandleError.hpp"
#include "HandleBadRequest.hpp"

using namespace api::v1;

void Auth::login(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback) const {

	// check if the request is a valid JSON
	auto jsonReq = req->getJsonObject();
	if(handleBadRequest(!jsonReq, "Invalid JSON body", callback)) return;
	
	if(handleBadRequest(!jsonReq->isMember("userId") || !(*jsonReq)["userId"].isString(), "Invalid 'userId' or 'password'", callback)) return;
	if(handleBadRequest(!jsonReq->isMember("password") || !(*jsonReq)["password"].isString(), "Invalid 'userId' or 'password'", callback)) return;

	// parse the JSON body
	std::string userId = (*jsonReq)["userId"].asString();
	std::string password = (*jsonReq)["password"].asString();

	// login the user
	auto result = AuthService::login(userId, password);
	if (handleError(result, callback)) return;

	// create a JSON response
	Json::Value data;
	data["userId"] = result.data.userId;
	data["username"] = result.data.username;
	data["role"] = result.data.role;

	Json::Value json;
	json["status"] = "success";
	json["message"] = "Login successful";
	json["data"] = data;

	// return response
	auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
	resp->setStatusCode(drogon::k200OK);

	callback(resp);
}