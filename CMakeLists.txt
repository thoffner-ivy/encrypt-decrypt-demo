cmake_minimum_required(VERSION 4.2.0)

project(EncryptDecryptDemo LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} src/main.c)
