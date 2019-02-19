all: oucat.c ouecho.c
	gcc -o oucat oucat.c
	gcc -o ouecho ouecho.c
	gcc -o ouhead ouhead.c

oucat: oucat.c
	gcc -o oucat oucat.c

ouecho: ouecho.c
	gcc -o ouecho ouecho.c

ouhead: ouhead.c
	gcc -o ouhead ouhead.c

clean: 
	rm oucat.o
	rm ouecho.o
	rm ouhead.o
