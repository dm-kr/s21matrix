CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LIBS = -lm

TARGET = s21_matrix.a

SRCS = *.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(filter-out main.o, $(OBJS))
	@ar rcs $@ $^
	@ranlib $@
	@rm $^

test: $(TARGET)
	@$(CC) $(CFLAGS) tests/*.c $^ -o tests/test
	@tests/test

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(TARGET) *.out tests/test

.PHONY: all clean $(TARGET)