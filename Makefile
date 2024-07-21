CFLAGS = -Wall -Wextra -Werror -std=c11
LIBS = -lm

TARGET = s21_matrix

SRCS = *.c

OBJS = $(SRCS:.c=.o)

all: s21_matrix.a

s21_matrix.a: $(filter-out main.o, $(OBJS))
	@ar rcs $@ $^
	@ranlib $@
	@rm $^

test: s21_matrix.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(TARGET)

.PHONY: all clean s21_matrix.a