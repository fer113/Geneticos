#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "individual.h"

using namespace std;

bool flip (int);

int
main (int argc, char *argv[]) 
{
  if (argc < 2) 
  {
    cout << "Not enough argmuents" << endl;
    return 1;
  }
  size_t generations = atoi (argv[1]);
  size_t pop_size = 16;
  ofstream fmax, fmin;
  fmax.open ("max.dat");
  fmin.open ("min.dat");
  vector < Individual > parents;
  vector < Individual > childs;
  vector < Individual > temp;
  vector < Individual >::iterator chit, chit2;
  srand ((int) time (0));
  parents.reserve (pop_size);
  childs.reserve (pop_size);
  double mmax = 0, mmin = 65535, mpro = 0;
  for ( size_t i = 0; i < pop_size; ++i )
  {
    parents.push_back ( Individual (1, 4) );
    mmax = parents.back().getAptitude() > mmax ? parents.back().getAptitude() : mmax;
    mmin = parents.back().getAptitude() < mmin ? parents.back().getAptitude() : mmin;
    mpro += parents.back().getAptitude();
  }
  mpro /= pop_size;
  cout << "Generation 0:\t";
  cout << "Max: " << mmax << "\tMin: " << mmin << endl;
  fmax << "0" << " " << mmax << endl;
  fmin << "0" << " " << mmin << endl;
  for ( size_t k = 0; k < generations; ++k)
  {
    for (size_t i = 0; i < pop_size; i+=2) 
    {
      int r1 = rand () % 4;
      temp = parents.at (i).cruzaUnPunto (parents.at (i+1), r1);
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      if (flip(1)) (*chit).mutate();
      if (flip(1)) (*(chit+1)).mutate();
    }
    parents.clear();
    double max = 0, min = 65535, pro = 0;
    sort(childs.begin(), childs.end(), compare_lt_ind() );
    for (size_t i = 0; i < pop_size; ++i)
    {
      childs.at(i).probability = 0.9 + 0.2 * ((double)i/(pop_size - 1));
      double apt = childs.at(i).getAptitude();
      min = apt < min ? apt : min;
      max = apt > max ? apt : max;
      pro += apt;
    }
    pro /= pop_size;
    random_shuffle (childs.begin(), childs.end() );
    for (size_t i = 0; i < pop_size; ++i)
    {
      double roll = rand()%pop_size;
      double accumulated = 0;
      for (Individual child : childs)
      {
        accumulated+= child.probability;
        if (accumulated >= roll)
        {
          parents.push_back(child);
          break;
        }
      }
    }
    childs.clear();
    cout << "Generation " << k+1 << ":\t";
    cout << "Max: " << max << "\tMin: " << min << endl;
    fmax << k+1 << " " << max << endl;
    fmin << k+1 << " " << min << endl;
  }
  fmax.close();
  fmin.close();
  system("gnuplot -p plot.gpl");
  return 0;
}

bool flip (int x)
{
  return (rand() % 10 + 1) <= x ;
}
