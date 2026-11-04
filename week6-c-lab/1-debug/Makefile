# Do not modify this Makefile. It builds two programs, like asgn5 builds three.
# `make` makes the first target, all, which needs both programs.

.PHONY: all clean
all: tohex fromhex

tohex: tohex.o
	clang tohex.o -o tohex

fromhex: fromhex.o
	clang fromhex.o -o fromhex

tohex.o: tohex.c
	clang -c -Wall -Werror -gdwarf-4 tohex.c

fromhex.o: fromhex.c
	clang -c -Wall -Werror -gdwarf-4 fromhex.c

clean:
	rm -f tohex fromhex *.o note.hex note.out odd.out
