#pragma once

#include <drogon/drogon.h>
#include "HttpResponseHelper.hpp"

inline bool handleBadRequest(bool condition, const std::string &message, const std::function<void(const drogon::HttpResponsePtr&)>& callback) {
	if (!condition) return false;

	drogon::LOG_WARNING << "Bad request: " << message; // Log the bad request for debugging

	callback(createErrorResponse(drogon::k400BadRequest, message));

	return true;
}