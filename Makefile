CC=gcc
CFLAGS=-Wall

all: sistema_estoque

sistema_estoque: src/main.c src/estoque.c
	$(CC) $(CFLAGS) src/main.c src/estoque.c -o sistema_estoque

clean:
	rm -f sistema_estoque *.o
