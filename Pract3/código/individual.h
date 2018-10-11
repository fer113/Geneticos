#ifndef __INDIVIDUAL_H__
#define __INDIVIDUAL_H__

#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include "gen.h"

class Individual {
private:
  std::vector < Gen > chromosome;
public:
  double probability;
  std::vector < bool > crossPoints;
  Individual (std::vector < bool >, size_t);
  Individual (std::vector < bool > vb) : Individual ( vb, 1) { }
  Individual (size_t n, size_t m);
  Individual (size_t n) : Individual (n, 5) { }
  Individual (void) : Individual (1, 5) { }
  int getAptitude (void);
  void copy (Individual& ind);
  std::string getChromosomeString (void);
  std::string getMarksString (void);
  std::vector < bool > getChromosome (void);
  std::vector < Individual > cruzaUnPunto (Individual&, size_t);
  std::vector < Individual > cruzaDosPuntos (Individual&, size_t, size_t);
  std::vector < Individual > cruzaUniforme (Individual&, std::set < int >);
  std::vector < Individual > cruzaAcentuada (Individual&);
  Individual mutate (void);
};

#endif
