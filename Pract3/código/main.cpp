#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "individual.h"

using namespace std;

int
main (int argc, char *argv[]) 
{
  if (argc < 3) 
  {
    cout << "Not enough argmuents" << endl;
    return 1;
  }
  size_t generations = atoi (argv[1]);
  size_t pop_size = atoi (argv[2]);
  ofstream fmax, fmin;
  fmax.open ("max.dat");
  fmin.open ("min.dat");
  vector < Individual > parents;
  vector < Individual > childs;
  vector < Individual > temp;
  vector < Individual >::iterator chit;
  srand ((int) time (0));
  parents.reserve (pop_size);
  childs.reserve (pop_size);
  for ( size_t i = 0; i < pop_size; ++i )
  {
    parents.push_back ( Individual (1, 5) );
  }
  for ( size_t k = 0; k < generations; ++k)
  {
    cout << "***** Generation :" << k+1 << " *****" << endl;
    for (size_t i = 0; i < pop_size/2; i+=2) 
    {
      int r1 = rand () % 5;
      temp = parents.at (i).cruzaUnPunto (parents.at (i+1), r1);
      chit = childs.insert (childs.end (), temp.begin (), temp.end ());
      (*chit).mutate();
      (*(chit+1)).mutate();
    }
    parents.clear();
    int total = 0;
    for(Individual child : childs)
    {
      total += child.getAptitude();
    }
    //total /= pop_size;
    cout << "total: " << total << endl;
    double max = 0, min = 65535;
    for(Individual child : childs)
    {
      int apt = child.getAptitude();
      child.probability = apt / (double)total;
      max = child.probability>max?child.probability:max;
      min = child.probability<min?child.probability:min;
    }
    for (size_t i = 0; i < pop_size; ++i)
    {
      double roll = rand()/RAND_MAX;
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
    cout << "Max: " << max << "\tMin: " << min << endl;
    fmax << k+1 << " " << max << '\n';
    fmin << k+1 << " " << min << '\n';
  }
  fmax.close();
  fmin.close();
  cout << "Plotting 'max.dat'..." << endl;
  system("gnuplot -p plot.gpl");
  return 0;
}
