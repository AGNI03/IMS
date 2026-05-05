file(GLOB_RECURSE SRC_FILES
    *.cpp
)

add_library(utils STATIC ${SRC_FILES})

target_include_directories(utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(utils PUBLIC
    Drogon::Drogon
)