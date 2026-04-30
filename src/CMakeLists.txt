file(GLOB_RECURSE SRC_FILES
    *.cpp
)

add_library(core OBJECT ${SRC_FILES})

target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(core PUBLIC
    Drogon::Drogon
    mysql::concpp
    third_party
)