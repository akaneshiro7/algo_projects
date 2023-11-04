# Makefile for C++ program

# Define the compiler and compilation flags
CXX = g++
CXXFLAGS = -std=c++17

# Define the source files and the object files
SRCS = main.cpp Deck.cpp Node.cpp Card.cpp

# Define the header files
HEADERS = Deck.h Node.h Card.h

# Define the target executable
TARGET = main

# Default target: build the program
all: run

# Compile the source files into object files
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run the compiled program
run: $(TARGET)
	./$(TARGET)

# Clean up the executable
clean:
	rm -f $(TARGET)