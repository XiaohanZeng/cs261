default: prog

cirListDeque.o: cirListDeque.c cirListDeque.h 
	gcc -Wall -std=c99 -g -c cirListDeque.c	

prog: cirListDeque.o
	gcc -Wall -std=c99 -g  -o prog cirListDeque.o listDequeTest.c 
		
clean:
	rm cirListDeque.o

cleanall: clean
	rm prog
