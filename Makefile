CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LIBS = -lm -lcheck -lsubunit

TARGET = s21_matrix.a

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@ar rcs $@ $^
	@ranlib $@
	@rm $^

main: $(TARGET)
	@$(CC) $(CFLAGS) tests/main.c s21_matrix.a $(LIBS) -o tests/main
	@tests/main

valmain: main
	@valgrind --tool=memcheck --leak-check=full tests/main

test: $(TARGET)
	@$(CC) $(CFLAGS) tests/general.c s21_matrix.a $(LIBS) -o tests/test
	@tests/test

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(TARGET) *.out tests/test

.PHONY: all clean $(TARGET)