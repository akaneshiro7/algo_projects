cmake_minimum_required(VERSION 3.21)
project(project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(project2 main.cpp Deck.cpp Deck.h Node.cpp Node.h Card.cpp Card.h)
