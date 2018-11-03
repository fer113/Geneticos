#include <iostream>
#include <vector>
#include <cstdlib>
#include "../../lib/individual.h"

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
    cout << "Cruza de un punto\n";
    break;
  case 2:
    cout << "Cruza de dos puntos\n";
    break;
  case 3:
    cout << "Cruza uniforme\n";
    break;
  case 4:
    cout << "Cruza acentuada\n";
    break;
  default:
    cout << "Opcion no valida\n";
    return 2;
    break;
  }
  vector < Individual > p1;
  vector < Individual > p2;
  vector < Individual > childs;
  vector < Individual > temp;
  vector < Individual >::iterator chit;
  srand ((int) time (0));
  p1.reserve (50);
  p2.reserve (50);
  childs.reserve (100);
  int r1;
  int r2;
  for (size_t i = 0; i < 50; i++) {
    p1.push_back (Individual (2, 4));
    cout << "\n****Cruza " << i + 1 << "****\n";
    cout << "--------Padre 1--------\n";
    cout << "Aptitud:\t" << p1.back ().getAptitude () << '\n';
    cout << "Cromosoma:\t" << p1.back ().getChromosomeString () << '\n';
    if (option == 4) {
      cout << "Marcas:\t\t" << p1.back ().getMarksString () << '\n';
    }
    p2.push_back (Individual (2, 4));
    cout << "--------Padre 2--------\n";
    cout << "Aptitud:\t" << p2.back ().getAptitude () << '\n';
    cout << "Cromosoma:\t" << p2.back ().getChromosomeString () << '\n';
    if (option == 4) {
      cout << "Marcas:\t\t" << p2.back ().getMarksString () << '\n';
    }
    set < int > uni;
    switch (option) {
    case 1:
      r1 = rand () % 8;
      cout << "Punto de Cruza: " << r1 << '\n';
      temp = p1.at (i).cruzaUnPunto (p2.at (i), r1);
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      break;
    case 2:
      r1 = rand () % 9;
      r2 = rand () % 9;
      if (r2 < r1) {
        int t = r1;
        r1 = r2;
        r2 = t;
      }
      cout << "Puntos de Cruza: " << r1 << "," << r2 << '\n';
      temp = p1.at (i).cruzaDosPuntos (p2.at (i), r1, r2);
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      break;
    case 3:
      cout << "Puntos de Cruza: ";
      do {
        uni.insert (rand () % 8);
      } while (uni.size() < 4);
      for(int unii : uni){
        cout << unii << " ";
      }
      cout << '\n';
      temp = p1.at (i).cruzaUniforme (p2.at (i), uni);
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      break;
    case 4:
      temp = p1.at (i).cruzaAcentuada (p2.at (i));
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      break;
    }
    cout << "--------Hijo 1--------\n";
    cout << "\tAptitud:\t" << (*chit).getAptitude () << '\n';
    cout << "\tCromosoma:\t" << (*chit).getChromosomeString () << '\n';
    if (option == 4) {
      cout << "\tMarcas:\t\t" << (*chit).getMarksString () << '\n';
    }
    cout << "--------Hijo 2--------\n";
    cout << "\tAptitud:\t" << (*(chit + 1)).getAptitude () << '\n';
    cout << "\tCromosoma:\t" << (*(chit + 1)).getChromosomeString () << '\n';
    if (option == 4) {
      cout << "\tMarcas:\t\t" << (*(chit + 1)).getMarksString () << '\n';
    }
  }
  return 0;
}
