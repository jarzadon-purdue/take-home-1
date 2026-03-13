# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror

# Files
TARGET = flesch
OBJS = main.o flesch.o
INPUTS = $(wildcard inputs/input_*.txt)
EXPECTED = $(INPUTS:inputs/input_%.txt=expected/expected_%.txt)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c flesch.h
	$(CC) $(CFLAGS) -c main.c

flesch.o: flesch.c flesch.h
	$(CC) $(CFLAGS) -c flesch.c

# Run all 8 tests automatically
test: $(TARGET)
	@mkdir -p output
	@for i in 1 2 3 4 5 6 7 8; do \
		echo "Testing input_$$i.txt..."; \
		./$(TARGET) inputs/input_$$i.txt > output/output_$$i.txt; \
		diff output/output_$$i.txt expected/expected_$$i.txt && echo "  PASSED ✅" || echo "  FAILED ❌"; \
	done

# Clean up
clean:
	rm -f $(TARGET) *.o
	rm -rf output