cmake_minimum_required(VERSION 3.16)
project(HTTP)

set(CMAKE_CXX_STANDARD 14)

add_executable(HTTP  server.cpp  parser.cpp parser.h Http.cpp connections.cpp)
add_executable(my_client  client.cpp)

#add_executable(problem1 server.c)
#add_executable(problem2 .c)

if(MINGW)
    target_link_libraries(HTTP ws2_32)
    target_link_libraries(my_client ws2_32)
endif()