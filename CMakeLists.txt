cmake_minimum_required(VERSION 3.17)
project(CursedCursor)

set(CMAKE_CXX_STANDARD 17)
if(MSVC)
    set(CMAKE_CXX_FLAGS "/D NOMINMAX /EHsc")
    add_compile_options(
            $<$<CONFIG:>:/MT>
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>
    )
endif()
add_executable(CursedCursor main.cpp)
