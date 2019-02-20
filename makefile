all: oucat.c ouecho.c
	gcc -o oucat oucat.c
	gcc -o ouecho ouecho.c
	gcc -o ouhead ouhead.c
	gcc -o outail outail.c

oucat: oucat.c
	gcc -o oucat oucat.c

ouecho: ouecho.c
	gcc -o ouecho ouecho.c

ouhead: ouhead.c
	gcc -o ouhead ouhead.c

outail: outail.c
	gcc -o outail outail.c

clean: 
	rm oucat.o
	rm ouecho.o
	rm ouhead.o
	rm outail.o
