OBJS = main.o mathfnc.o stack.o getop.o getch.o 
BINARY = main
CFLAGS = -Wall -fdiagnostics-color=always -g
LDFLAGS = -lm

all: main
# esta regla compila el programa principal
main: $(OBJS)
	gcc $(OBJS) $(LDFLAGS) -o $(BINARY)
main.o: main.c calc.h
	gcc $(CFLAGS) -c main.c
mathfnc.o: mathfnc.c calc.h
	gcc $(CFLAGS) -c mathfnc.c
stack.o: stack.c calc.h
	gcc $(CFLAGS) -c stack.c
getop.o: getop.c calc.h
	gcc $(CFLAGS) -c getop.c
getch.o: getch.c calc.h
	gcc $(CFLAGS) -c getch.c
clean:
	rm -f $(OBJS)