cmake_minimum_required(VERSION 3.10)
project(hangman)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(markov
        main.cpp
        markov.cpp
        markov.h
        model.h
        brute_model.cpp
        brute_model.h
        map_model.cpp
        map_model.h
        word_model.cpp
        word_model.h)
