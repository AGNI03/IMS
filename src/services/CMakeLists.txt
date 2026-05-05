file(GLOB_RECURSE SRC_FILES
    *.cpp
)

add_library(services STATIC ${SRC_FILES})

target_include_directories(services PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(services PUBLIC
    jwt-cpp::jwt-cpp
    models
    database
    third_party
)