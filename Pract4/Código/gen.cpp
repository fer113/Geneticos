#include "gen.h"

Gen::Gen (size_t n) 
{
  for (size_t i = 0; i < n; i++) 
  {
    gen.push_back (rand () % 2);
  }
}

Gen::Gen ( std::vector < bool > g ) 
{
  gen = g;
}

int
Gen::getValue (void) 
{
  int result = 0;
  for (int i = gen.size () - 1, j = 0; i > -1; i--, j++) 
  {
    if (gen.at (i)) 
    {
      result += (1 << j);
    }
  }
  return result;
}

void
Gen::mutate ( void )
{
  size_t position = rand()% gen.size();
  gen.at(position) = gen.at(position)?false:true;
}