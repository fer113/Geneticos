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
    cout << "Order Crossover\n";
    break;
  case 2:
    cout << "Partially Mapped Crossover\n";
    break;
  case 3:
    cout << "Position Based Crossover\n";
    break;
  case 4:
    cout << "Order Based Crossover\n";
    break;
  case 5:
    cout << "Cycle Crossover\n";
    break;
  default:
    cout << "Opcion no valida\n";
    return 2;
    break;
  }
  vector < IntegerIndividual > p1;
  vector < IntegerIndividual > p2;
  vector < IntegerIndividual > childs;
  vector < IntegerIndividual > temp;
  vector < IntegerIndividual >::iterator chit;
  srand ((int) time (0));
  p1.reserve (50);
  p2.reserve (50);
  childs.reserve (100);
  for (size_t i = 0; i < 50; i++) {
    p1.push_back ( IntegerIndividual (10) );
    cout << "\n****Cruza " << i + 1 << "****\n";
    cout << "--------Padre 1--------\n";
    cout << "Cromosoma:\t" << p1.back ().getChromosomeString () << '\n';
    p2.push_back ( IntegerIndividual (10) );
    cout << "--------Padre 2--------\n";
    cout << "Cromosoma:\t" << p2.back ().getChromosomeString () << '\n';
    switch (option) {
    case 1:
      temp = p1.at (i).orderCrossover (p2.at (i));
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      break;
    case 2:
      temp = p1.at (i).partiallyMappedCrossover (p2.at (i));
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      break;
    case 3:
      temp = p1.at (i).positionBasedCrossover (p2.at (i));
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      break;
    case 4:
      temp = p1.at (i).orderBasedCrossover (p2.at (i));
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      break;
    case 5:
      temp = p1.at (i).cycleCrossover (p2.at (i));
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      break;
    }
    cout << "--------Hijo 1--------\n";
    cout << "Cromosoma:\t" << (*chit).getChromosomeString () << '\n';
    cout << "--------Hijo 2--------\n";
    cout << "Cromosoma:\t" << (*(chit + 1)).getChromosomeString () << '\n';
  }
  return 0;
}
