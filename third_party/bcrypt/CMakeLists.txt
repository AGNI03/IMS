add_library(bcrypt)

target_sources(bcrypt PRIVATE
    bcrypt.cpp
    blowfish.cpp
)



target_include_directories(bcrypt
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
