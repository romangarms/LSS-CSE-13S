# Do not modify this Makefile.

.PHONY: all clean
all: numlines

numlines: numlines.o linewriter.o
	clang numlines.o linewriter.o -o numlines

numlines.o: numlines.c linewriter.h
	clang -c -Wall -Werror -gdwarf-4 numlines.c

linewriter.o: linewriter.c linewriter.h
	clang -c -Wall -Werror -gdwarf-4 linewriter.c

clean:
	rm -f numlines *.o todo.out
