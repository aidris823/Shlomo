all: fidder_on_the_roof.o
	gcc fidder_on_the_roof.o -lm
fidder_on_the_roof.o: fidder_on_the_roof.c
	gcc -c fidder_on_the_roof.c
run:
	./a.out
clean: 
	rm *.o