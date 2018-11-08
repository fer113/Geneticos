#ifndef __INTEGERINDIVIDUAL_H__
#define __INTEGERINDIVIDUAL_H__
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>

class IntegerIndividual {
private:
  std::vector < int > chromosome;
public:
  IntegerIndividual (std::vector < int >);
  IntegerIndividual (size_t n);
  IntegerIndividual (void): IntegerIndividual(10) {}
  int getAptitude (void);
  std::vector < int > getChromosome (void);
  std::string getChromosomeString (void);
  std::string getMarksString (void);
  std::vector < IntegerIndividual > orderCrossover (IntegerIndividual, size_t, size_t);
  std::vector < IntegerIndividual > orderCrossover (IntegerIndividual);
  std::vector < IntegerIndividual > partiallyMappedCrossover (IntegerIndividual, size_t, size_t);
  std::vector < IntegerIndividual > partiallyMappedCrossover (IntegerIndividual);
  std::vector < IntegerIndividual > positionBasedCrossover (IntegerIndividual, std::set < int > index);
  std::vector < IntegerIndividual > positionBasedCrossover (IntegerIndividual);
  std::vector < IntegerIndividual > orderBasedCrossover (IntegerIndividual,std::set < int > index);
  std::vector < IntegerIndividual > orderBasedCrossover (IntegerIndividual);
  std::vector < IntegerIndividual > cycleCrossover (IntegerIndividual, size_t);
  std::vector < IntegerIndividual > cycleCrossover (IntegerIndividual);
  IntegerIndividual mut_insercion (void);
  IntegerIndividual mut_desplazamiento (void);
  IntegerIndividual mut_intercambio_reciproco (void);
  IntegerIndividual mut_heuristica (void);
};

#endif
