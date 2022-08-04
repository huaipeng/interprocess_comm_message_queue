
cmake_minimum_required(VERSION 3.0)
project (test_boost_message_queue)

# CPP 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


find_package(Boost 1.6.0 REQUIRED COMPONENTS filesystem system iostreams serialization)
include_directories(${Boost_INCLUDE_DIRS})

 
# Set directory for Source files
file(GLOB SOURCES "*.cpp" )

include_directories(./)

# Add executable file
add_executable(test_boost_message_queue ${SOURCES})
target_link_libraries(test_boost_message_queue ${Boost_LIBRARIES})




