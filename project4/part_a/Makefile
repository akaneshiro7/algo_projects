# Compiler
CC=g++

# Compile flags
CFLAGS=-I. -Wall

# Object files
OBJ=main.o 

# Executable name
EXEC= part_a 

# Default target
all: run

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
run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)