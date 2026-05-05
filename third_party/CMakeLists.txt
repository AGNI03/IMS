file(GLOB_RECURSE SRC_FILES
    *.cpp
)

add_library(third_party STATIC ${SRC_FILES})

target_include_directories(third_party PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)