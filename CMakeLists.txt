cmake_minimum_required(VERSION 3.30)
project(Tetris_LAB_EDA C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Tetris_LAB_EDA
    common.h
    game.c
    game.h
    main.c
    main.h
    pieces.c
    pieces.h
    session.c
    session.h
    utils.c
    utils.h)
