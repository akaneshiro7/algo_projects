# Compiler
CC=g++

# Compile flags
CFLAGS=-I. -Wall

# Object files
OBJ=main.o heap.o

# Executable name
EXEC=myProgram

# Default target
all: $(EXEC)

# Link the program
$(EXEC): $(OBJ)
	$(CC) -o $@ $^

# Compile the source files
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Clean up
clean:
	rm -f $(OBJ) $(EXEC)

# Run the program
run: all
	./$(EXEC)
