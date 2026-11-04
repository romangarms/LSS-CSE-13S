# Do not modify this Makefile. It builds two programs, like asgn5 builds three.
# `make` makes the first target, all, which needs both programs.

.PHONY: all clean
all: encode decode

encode: encode.o
	clang encode.o -o encode

decode: decode.o
	clang decode.o -o decode

encode.o: encode.c
	clang -c -Wall -Werror -gdwarf-4 encode.c

decode.o: decode.c
	clang -c -Wall -Werror -gdwarf-4 decode.c

clean:
	rm -f encode decode *.o note.code note.out cut.out
