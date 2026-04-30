#pragma once

#include <drogon/HttpController.h>

namespace api::v1 {

    class Auth : public drogon::HttpController<Auth>
    {
    public:
	    // declare the path of the controllers
        METHOD_LIST_BEGIN
            METHOD_ADD(Auth::login, "/login", drogon::Post);
        METHOD_LIST_END
                
	    // declare the method of the controllers
		// login method /api/v1/auth/login
        void login(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback) const;
    };

} // namespace api::v1