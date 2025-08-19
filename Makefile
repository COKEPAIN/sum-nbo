#Makefile
all: sum-nbo

sum-nbo: 
	gcc -o sum-nbo sum-nbo.c

clean:
	rm -f sum-nbo

