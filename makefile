all: exec

exec: main.o readFiles.o
	gcc -g -o exec main.o readFiles.o

main.o: main.c
	gcc -g -o main.o main.c -c -W -Wall -ansi -pedantic

readFiles.o:
	gcc -g -o readFiles.o readFiles.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
	#del /Q /S *.o *~ math

run:
	make clean
	make all