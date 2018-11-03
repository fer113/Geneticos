run:	main
	./main 4
all:	main.cpp individual.o gen.o
	g++ -o main main.cpp individual.o gen.o -Wall -O3
individual.o:	individual.h individual.cpp gen.o
	g++ -c individual.cpp -Wall -O3
gen.o:	gen.h gen.cpp
	g++ -c gen.cpp -Wall
clean:
	rm -f *~ *.o main 
