# Компилятор и флаги
CC = gcc
CFLAGS = -m32 -std=c99 -Wall -Wextra
NASMFLAGS = -f elf32 -g -F dwarf
LDFLAGS = -m32 -no-pie -z noexecstack

# Цели
all: program

# Правила компиляции
main.o: main.c funcs.h main.h
	$(CC) $(CFLAGS) -c -o $@ $<

funcs.o: funcs.asm
	nasm $(NASMFLAGS) -o $@ $<

root.o: root.c main.h
	$(CC) $(CFLAGS) -c -o $@ $<

integral.o: integral.c main.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Линковка
program: main.o funcs.o root.o integral.o
	$(CC) $(LDFLAGS) -o $@ $^ -lm

# Очистка
clean:
	rm -f *.o program

.PHONY: all clean