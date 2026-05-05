cmake_minimum_required(VERSION 3.22)

project(ims)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#find_package(fmt CONFIG REQUIRED)
find_package(mysql-concpp CONFIG REQUIRED)
find_package(Drogon CONFIG REQUIRED)
find_package(jwt-cpp CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(third_party)

add_executable(ims main.cpp)

target_link_libraries(ims PRIVATE
    Drogon::Drogon
)

# Link the controllers library with whole archive to ensure all symbols are included
if (MSVC)
    target_link_libraries(ims PRIVATE controllers)
    target_link_options(ims PRIVATE /WHOLEARCHIVE:controllers)
else()
    target_link_libraries(ims PRIVATE
        -Wl,--whole-archive controllers -Wl,--no-whole-archive
    )
endif()

# Set warning levels and treat warnings as errors
if (MSVC)
    target_compile_options(ims PRIVATE
        /W4
        /external:anglebrackets
        /external:W0
    )
endif()