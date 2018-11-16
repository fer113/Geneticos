#include <iostream>
#include <vector>
#include <cstdlib>
#include "../../lib/integerindividual.h"

using namespace std;

int
main (int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Not enough argmuents" << endl;
    return 1;
  }
  int option = atoi (argv[1]);
  switch (option) {
  case 1:
    cout << "Mutacion por insercion\n";
    break;
  case 2:
    cout << "Mutacion por desplazamiento\n";
    break;
  case 3:
    cout << "Mutacion por intercambio reciproco\n";
    break;
  case 4:
    cout << "Mutacion Heuristica\n";
    break;
  default:
    cout << "Opcion no valida\n";
    return 2;
    break;
  }
  vector < IntegerIndividual > p1;
  vector < IntegerIndividual > p2;
  vector < IntegerIndividual > childs;
  IntegerIndividual temp;
  srand ((int) time (0));
  p1.reserve (100);
  childs.reserve (100);
  for (size_t i = 0; i < 100; i++) {
    p1.push_back ( IntegerIndividual (10) );
    cout << "\n****Mutacion " << i + 1 << "****\n";
    cout << "--------Padre 1--------\n";
    cout << "Cromosoma:\t" << p1.back ().getChromosomeString () << '\n';
    switch (option) {
    case 1:
      temp = p1.at (i).mut_insercion ();
      break;
    case 2:
      temp = p1.at (i).mut_desplazamiento ();
      break;
    case 3:
      temp = p1.at (i).mut_intercambio_reciproco ();
      break;
    case 4:
      temp = p1.at (i).mut_heuristica ();
      break;
    }
    childs.push_back(temp);
    cout << "--------Hijo 1--------\n";
    cout << "Cromosoma:\t" << temp.getChromosomeString () << '\n';
  }
  return 0;
}
