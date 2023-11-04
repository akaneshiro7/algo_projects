cmake_minimum_required(VERSION 3.26)
project(part_a)

set(CMAKE_CXX_STANDARD 17)

add_executable(part_a main.cpp Deck.cpp Deck.h Node.cpp Node.h Card.cpp Card.h)
