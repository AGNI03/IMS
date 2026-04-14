cmake_minimum_required(VERSION 3.22)

project(ims)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(fmt CONFIG REQUIRED)
find_package(mysql-concpp REQUIRED)
find_package(Drogon CONFIG REQUIRED)

add_executable(ims "main.cpp")

add_subdirectory(third_party)
add_subdirectory(src)

target_link_libraries(ims PRIVATE
    Drogon::Drogon
)

target_link_libraries(ims PRIVATE
    env_loader
)



# ---- MSVC external warnings suppression ----
if (MSVC)
    target_compile_options(ims PRIVATE
        /W4
        /external:anglebrackets
        /external:W0
    )
endif()