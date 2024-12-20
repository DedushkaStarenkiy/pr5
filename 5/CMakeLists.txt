cmake_minimum_required(VERSION 3.10)
project(ConsoleUtility C)

set(CMAKE_C_STANDARD 11)

add_executable(ConsoleUtility
    main.c
    users.c
    processes.c
    help.c
    log.c
    errors.c
)

target_include_directories(ConsoleUtility PRIVATE ${CMAKE_SOURCE_DIR})

