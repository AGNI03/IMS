cmake_minimum_required(VERSION 3.22)

project(ims)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#find_package(fmt CONFIG REQUIRED)
find_package(mysql-concpp CONFIG REQUIRED)
find_package(Drogon CONFIG REQUIRED)
find_package(jwt-cpp CONFIG REQUIRED)


add_executable(ims main.cpp $<TARGET_OBJECTS:core>)

add_subdirectory(src)
add_subdirectory(third_party)

target_link_libraries(ims PRIVATE
    core
    Drogon::Drogon
)

if (MSVC)
    target_compile_options(ims PRIVATE
        /W4
        /external:anglebrackets
        /external:W0
    )
endif()