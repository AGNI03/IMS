add_library(services)

target_sources(services PRIVATE
    authService.cpp
)

target_link_libraries(services PUBLIC
    database
    models
    bcrypt
)

target_link_libraries(services PRIVATE
    exceptions
)

target_include_directories(services PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)