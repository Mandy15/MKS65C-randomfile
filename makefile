all: randomfile.o
	gcc -o randomfile randomfile.o

randomfile.o: randomfile.c
	gcc -c randomfile.c

clean:
	rm randomfile randomfile.o file.txt

run:
	./randomfile
