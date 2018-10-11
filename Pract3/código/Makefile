run:	main
	./main 5 50
	./main 10 50
	./main 15 50
main:	main.cpp individual.o gen.o
	g++ -o main main.cpp individual.o gen.o -Wall
individual.o: individual.h individual.cpp
	g++ -c individual.cpp -Wall
gen.o:	gen.h gen.cpp
	g++ -c gen.cpp -Wall
clean:
	rm -f *.o main
