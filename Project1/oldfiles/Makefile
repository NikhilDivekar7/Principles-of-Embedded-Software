flags = -g -Werror -Wall -O0 -std=c99 -DVERBOSE
project: project1.o main.o debug.o conversion.o memory.o
	gcc -o project project1.o main.o debug.o conversion.o memory.o

main.0: main.c
	gcc -c main.c $(flags)

main.asm: main.c
	gcc -S main.c $(flags)

main.i: main.c
	gcc -E main.c $(flags)

conversion.o: conversion.c conversion.h
	gcc -c conversion.c $(flags)

conversion.asm: conversion.c conversion.h
	gcc -S conversion.c $(flags)

conversion.i: conversion.c conversion.h
	gcc -E conversion.c $(flags)

debug.o: debug.c debug.h
	gcc -c debug.c $(flags)

debug.asm: debug.c debug.h
	gcc -S debug.c $(flags)

debug.i: debug.c debug.h
	gcc -E debug.c $(flags)

memory.o: memory.c memory.h
	gcc -c memory.c $(flags)

memory.asm: memory.c memory.h
	gcc -S memory.c $(flags)

memory.i: memory.c memory.h
	gcc -E memory.c $(flags)

project1.o: project1.c project1.h
	gcc -c project1.c $(flags)

project1.asm: project1.c project1.h
	gcc -S project1.c $(flags)

project1.i: project1.c project1.h
	gcc -E project1.c $(flags)

clean:
	rm -f main.o
	rm -f conversion.o
	rm -f debug.o
	rm -f memory.o
	rm -f project1.o

