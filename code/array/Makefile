CC = gcc
CFLAGS = -Wall -Iinclude
SRCS = src/main.c src/sort.c src/reverse.c src/max.c
OBJS = $(SRCS:.c=.o)
TARGET = main_program

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
