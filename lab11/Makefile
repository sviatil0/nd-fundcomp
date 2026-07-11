CC = gcc
CFLAGS = -Wall -lm -lX11

snake: project.o func.o gfx.o
	$(CC) project.o func.o gfx.o $(CFLAGS) -o project 

snake.o: project.c func.h func.o
	$(CC) -c project.c -Wall

func.o: func.c
	$(CC) -c func.c -Wall