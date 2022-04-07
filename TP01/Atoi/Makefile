CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=monatoi

all: $(EXEC)

monatoi: atoi.o monatoi.o
	$(CC) -o $@ $^ $(LDFLAGS)

monatoi.o: atoi.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)