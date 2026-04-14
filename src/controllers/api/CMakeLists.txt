# CMakeLists.txt for the API controllers

add_library(api)

target_sources(api PRIVATE
    AuthController.cpp
)

# interface dependencies
target_link_libraries(api PRIVATE
    models
    exceptions
)

# implementation dependencies
target_link_libraries(api PRIVATE
    Drogon::Drogon
    services
)