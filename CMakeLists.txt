cmake_minimum_required(VERSION 3.10)
project(yaml-service-example)

set(CMAKE_CXX_STANDARD 17)

find_package(YAML-CPP)

include_directories(include libs/rtl/include ${custom_interfaces_INCLUDE_DIRS})

add_executable(yaml-service-example example/main.cpp)
target_link_libraries(yaml-service-example yaml-cpp)