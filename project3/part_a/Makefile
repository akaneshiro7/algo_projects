# Makefile for Dictionary and Grid project

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -g

# Define all object files
OBJS = main.o

# Name of the executable
EXEC = part_a

# Default target
all: run

# Linking all object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compiling Dictionary.cpp to Dictionary.o
Dictionary.o: Dictionary.cpp Dictionary.h
	$(CXX) $(CXXFLAGS) -c Dictionary.cpp

# Compiling Grid.cpp to Grid.o
Grid.o: Grid.cpp Grid.h
	$(CXX) $(CXXFLAGS) -c Grid.cpp

# Compiling main.cpp to main.o
main.o: main.cpp Dictionary.h Grid.h
	$(CXX) $(CXXFLAGS) -c main.cpp

run:  $(EXEC)
	./$(EXEC)
# Clean target to remove all object files and executable
clean:
	rm -f $(OBJS) $(EXEC)
