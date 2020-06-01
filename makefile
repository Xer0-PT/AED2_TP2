all: exec

exec: main.o readFiles.o line1.o line2.o
	gcc -g -o exec main.o readFiles.o line1.o line2.o

main.o: main.c
	gcc -g -o main.o main.c -c -W -Wall -ansi -pedantic

readFiles.o:
	gcc -g -o readFiles.o readFiles.c -c -W -Wall -ansi -pedantic

line1.o:
	gcc -g -o line1.o line1.c -c -W -Wall -ansi -pedantic

line2.o:
	gcc -g -o line2.o line2.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
	#del /Q /S *.o *~ math

run:
	make clean
	make all