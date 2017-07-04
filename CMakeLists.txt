cmake_minimum_required(VERSION 3.6)
set(CMAKE_C_STANDARD 11)

project(simple)
add_executable(simple main.c)

project(client)
add_executable(client src/client/client.c)

project(server)
add_executable(server src/server/server.c)