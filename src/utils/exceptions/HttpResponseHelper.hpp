#pragma once

#include <drogon/drogon.h>
#include <string>

inline HttpResponsePtr createErrorResponse(drogon::HttpStatusCode statusCode, const std::string &message) {
	Json::Value json;
	json["success"] = false;
	json["error"] = message;

	auto response = drogon::HttpResponse::newHttpJsonResponse(json);
	response->setStatusCode(statusCode);
	return response;
}