advanced_pointers: main.o advanced_pointers.o
	gcc -o advanced_pointers main.o advanced_pointers.o
	$(RM) *.o
main.o: main.c advanced_pointers.h
	gcc -c main.c
advanced_pointers.o: advanced_pointers.c advanced_pointers.h
	gcc -c advanced_pointers.c