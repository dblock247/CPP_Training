cmake_minimum_required(VERSION 3.9)
project(CPP_Training)

set(CMAKE_CXX_STANDARD 11)
set(Boost_USE_MULTITHREAD ON)
set(Boost_ADDITIONAL_VERSIONS "1.65" "1.65.0")
find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(CPP_Training main.cpp)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    target_link_libraries(CPP_Training ${Boost_LIBRARIES})
    # target_link_libraries(sandbox ${Boost_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
endif()