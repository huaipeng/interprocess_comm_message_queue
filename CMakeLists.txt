
cmake_minimum_required(VERSION 3.0)
project (message_queue_comm.exe)

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
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})




