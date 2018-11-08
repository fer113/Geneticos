run:
	./main 3
all:	main.cpp integerindividual.o
	g++ -o main main.cpp integerindividual.o -Wall -O3
integerindividual.o:	integerindividual.h integerindividual.cpp
	g++ -c integerindividual.cpp -Wall -O3
clean:
	rm -f *~ *.o main 
