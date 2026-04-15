#pragma once

#include <drogon/drogon.h>
#include <string>

inline drogon::HttpResponsePtr createErrorResponse(drogon::HttpStatusCode statusCode, const std::string &message) {
	Json::Value json;
	json["status"] = "error";
	json["message"] = message;

	auto response = drogon::HttpResponse::newHttpJsonResponse(json);
	response->setStatusCode(statusCode);
	return response;
}