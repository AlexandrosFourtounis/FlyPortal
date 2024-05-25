CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c libs/utils.c -g

clean:
	rm -f main