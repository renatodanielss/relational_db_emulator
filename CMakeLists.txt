cmake_minimum_required(VERSION 3.24)
project(relational_db_emulator C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)
add_executable(relational_db_emulator src/main.c src/core/usecase/insert.h)