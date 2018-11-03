#ifndef __GEN_H__
#define __GEN_H__

#include <vector>
#include <cstdlib>
#include <string>
#include <set>

class Gen {
public:
  std::vector < bool > gen;
  Gen (std::vector < bool >);
  Gen (size_t n);
  int getValue (void);
  void mutate (void);
};

#endif
