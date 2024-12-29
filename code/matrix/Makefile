CC = gcc
CFLAGS = -Wall -I.

SRCS = main.c point_wise_product.c matrix_product.c
OBJS = $(SRCS:.c=.o)
TARGET = matrix.app

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
