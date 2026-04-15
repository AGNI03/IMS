#pragma once

#include <drogon/drogon.h>
#include "Result.hpp"
#include "HttpResponseHelper.hpp"

template <typename T>
bool handleError(const Result<T>& result, const std::function<void(const drogon::HttpResponsePtr&)>& callback) {
	if (result.success) return false; // No error, continue with normal processing

	switch (result.error) {

	case ErrorType::VALIDATION_ERROR:
		LOG_WARN << "Validation error: " << result.message; // Log the validation error for debugging
		callback(createErrorResponse(drogon::k400BadRequest, result.message));
		return true;

	case ErrorType::NOT_FOUND_ERROR:
		LOG_WARN << "Not found error: " << result.message; // Log the not found error for debugging
		callback(createErrorResponse(drogon::k404NotFound, result.message));
		return true;

	case ErrorType::INTERNAL_ERROR:
		LOG_ERROR << "Internal error: " << result.message; // Log the internal error for debugging
		callback(createErrorResponse(drogon::k500InternalServerError, "Something went wrong"));
		return true;

	default:
		LOG_ERROR << "Unknown error type: " << result.message; // Log the unknown error for debugging
		callback(createErrorResponse(drogon::k500InternalServerError, "Something went wrong"));
		return true;
	}
}