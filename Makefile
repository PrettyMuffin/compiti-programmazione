LIBS = ./lib
CC = gcc
FLAGS = -g -O0 -L${LIBS} -I${LIBS} -lbasic

libs: ${LIBS}/libbasic.a

%.o: %.c
	${CC} -g -O0 -o $@ -c $< -Wall

HEADERS = ${shell find ${LIBS}/basic/ -name '*.h'}
SOURCES = ${shell find ${LIBS}/basic/ -name '*.c'}
OBJS = ${SOURCES:.c=.o}

${LIBS}/libbasic.a: ${HEADERS} ${OBJS}
	ar rcs ${LIBS}/libbasic.a ${OBJS}

all: libs main.c
	${CC} -o execute main.c ${FLAGS}

clean:
	find ../ -name '*.o' -delete
	find ../ -name '*.a' -delete
	rm execute
