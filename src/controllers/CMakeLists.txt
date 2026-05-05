file(GLOB_RECURSE SRC_FILES
    *.cpp
)

add_library(controllers STATIC ${SRC_FILES})

target_include_directories(controllers PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(controllers PUBLIC
    Drogon::Drogon
    services
    models
    utils
)