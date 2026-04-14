add_library(database)

target_sources(database PRIVATE
    userRepo.cpp
)

target_link_libraries(database PUBLIC
    mysql::concpp
    models
)

target_include_directories(database PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)
