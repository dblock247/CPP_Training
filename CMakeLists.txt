cmake_minimum_required(VERSION 3.9)
project(CPP_Training)

set(CMAKE_CXX_STANDARD 11)
set(Boost_USE_MULTITHREAD ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)

find_package(Boost COMPONENTS system filesystem program_options REQUIRED)
add_executable(CPP_Training main.cpp)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    target_link_libraries(CPP_Training ${Boost_LIBRARIES})
endif()


