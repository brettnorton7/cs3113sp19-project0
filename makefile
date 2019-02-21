all: oucat.c ouecho.c
	gcc -o oucat oucat.c
	gcc -o ouecho ouecho.c
	gcc -o ouhead ouhead.c
	gcc -o outail outail.c
	gcc -o ouseq ouseq.c
	gcc -o ouwc ouwc.c

oucat: oucat.c
	gcc -o oucat oucat.c

ouecho: ouecho.c
	gcc -o ouecho ouecho.c

ouhead: ouhead.c
	gcc -o ouhead ouhead.c

outail: outail.c
	gcc -o outail outail.c

ouseq: ouseq.c
	gcc -o ouseq ouseq.c

ouwc: ouwc.c
	gcc -o ouwc ouwc.c

clean: 
	rm oucat.o
	rm ouecho.o
	rm ouhead.o
	rm outail.o
	rm ouseq.o
	rm ouwc.o
