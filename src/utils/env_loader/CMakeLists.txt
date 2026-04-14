add_library(env_loader)

target_sources(env_loader PRIVATE EnvLoader.cpp)

target_include_directories(env_loader
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

