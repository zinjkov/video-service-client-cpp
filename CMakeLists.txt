cmake_minimum_required(VERSION 3.6)
project(zmqclient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)

set(SOURCE_FILES main.cpp
        VideoStreamClient.cpp)
add_executable(zmqclient ${SOURCE_FILES})
target_link_libraries(zmqclient -lpthread ${OpenCV_LIBS} -lzmq)