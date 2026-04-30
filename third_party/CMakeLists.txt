file(GLOB_RECURSE THIRD_PARTY
    *.cpp
)

add_library(third_party ${THIRD_PARTY})

target_include_directories(third_party PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)