CC = gcc
OBJ = board.o tests.c

%.o: %.c
	${CC} -c $< -o $@

tests: ${OBJ}
	${CC} ${OBJ} -o $@

clear:
	rm *.o tests