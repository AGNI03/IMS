file(GLOB_RECURSE SRC_FILES
    *.cpp
)

add_library(database STATIC ${SRC_FILES})

target_include_directories(database PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(database PUBLIC
    mysql::concpp
    models
)