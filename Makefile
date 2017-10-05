all: clear res clean

clear:
	clear

res: main.o vec_fun.o newton.o tangent.o golden_section.o bust.o crushing_step.o bisection.o
	gcc main.o vec_fun.o newton.o tangent.o golden_section.o bust.o bisection.o crushing_step.o -o res -lm

main.o: main.c
	gcc -c main.c
	
bust.o: bust.c
	gcc -c bust.c

bisection.o: bisection.c
	gcc -c bisection.c

newton.o: newton.c
	gcc -c newton.c

golden_section.o: golden_section.c
	gcc -c golden_section.c

tangent.o: tangent.c
	gcc -c tangent.c

crushing_step.o: crushing_step.c
	gcc -c crushing_step.c

vec_fun.o: vec_fun.c
	gcc -c vec_fun.c

clean:
	rm -rf *.o
