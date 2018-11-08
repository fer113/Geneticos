#include "integerindividual.h"

IntegerIndividual::IntegerIndividual (size_t n) {
  while (chromosome.size() < n) {
    int x = rand() % n + 1;
    if ( std::find(chromosome.begin(), chromosome.end(), x) == chromosome.end() ) {
      chromosome.push_back ( x );
    }
  }
}

IntegerIndividual::IntegerIndividual (std::vector < int > v) {
  chromosome = v;
}

std::vector < int > 
IntegerIndividual::getChromosome (void) {
  return chromosome;
}

std::string
IntegerIndividual::getChromosomeString (void) {
  std::string result;
  for (int alel : chromosome) {
    result+= std::to_string(alel) + " ";
  }
  return result;
}

std::vector < IntegerIndividual > 
IntegerIndividual::orderCrossover (IntegerIndividual spouse, size_t a, size_t b) {
  std::vector < IntegerIndividual > result;
  std::vector < int > parent1 = getChromosome();
  std::vector < int > parent2 = spouse.getChromosome();
  std::vector < int > child1(parent1.size(),-1), child2(parent1.size(),-1);
  size_t t = a;
  a = a<b?a:b;
  b = b<t?t:b;
  for(size_t i = a; i <= b ; i++) {
    child1.at(i) = parent1.at(i);
    child2.at(i) = parent2.at(i);
  }
  for(std::vector < int >::iterator itp = parent2.begin(), itc = child1.begin(); itp != parent2.end() && itc != child1.end() ; ) {
    if( *itc == -1 ) {
      if ( std::find(child1.begin(),child1.end(),*itp) == child1.end() ) {
        *itc = *itp;
        itp++;
        itc++;
      } else {
        itp++;
      }
    } else {
      itc++;
    }
  }
  for(std::vector < int >::iterator itp = parent1.begin(), itc = child2.begin(); itp != parent1.end() && itc != child2.end() ; ) {
    if( *itc == -1 ) {
      if ( std::find(child2.begin(),child2.end(),*itp) == child2.end() ) {
        *itc = *itp;
        itp++;
        itc++;
      } else {
        itp++;
      }
    } else {
      itc++;
    }
  }
  result.push_back( IntegerIndividual(child1) );
  result.push_back( IntegerIndividual(child2) );
  return result;
}

std::vector < IntegerIndividual > 
IntegerIndividual::orderCrossover (IntegerIndividual spouse) {
  size_t a = rand() % chromosome.size(), b = rand() % chromosome.size();
  while ( a == b ) {
    b = rand() % chromosome.size();
  }
  size_t t = a;
  a = a<b?a:b;
  b = b<t?t:b;
  std::cout << "Posicion de subcadena: " << a << ":"<< b << std::endl;
  return orderCrossover( spouse, a, b );
}

std::vector < IntegerIndividual > 
IntegerIndividual::partiallyMappedCrossover (IntegerIndividual spouse, size_t a, size_t b) {
  std::vector < IntegerIndividual > result;
  std::vector < int > parent1 = getChromosome();
  std::vector < int > parent2 = spouse.getChromosome();
  std::vector < int > child1(parent1.size(),-1), child2(parent2.size(),-1);
  size_t t = a;
  a = a<b?a:b;
  b = b<t?t:b;
  for(size_t i = a; i <= b ; i++) {
    child1.at(i) = parent1.at(i);
    child2.at(i) = parent2.at(i);
  }
  std::vector <int>::iterator it;
  for(size_t i = 0, j = 0; i < parent2.size() && j < child1.size() ; j++,i++) { 
    if( child1.at(j) == -1 ) {
      if ( (it = std::find(child1.begin(),child1.end(), parent2.at(i) ) ) == child1.end() ) {
        child1.at(j) = parent2.at(i);
      } else {
        child1.at(j) = parent2.at(it - child1.begin() );
      }
    }
  }
  for(size_t i = 0, j = 0; i < parent1.size() && j < child2.size() ; j++,i++) { 
    if( child2.at(j) == -1 ) {
      if ( (it = std::find(child2.begin(),child2.end(), parent1.at(i) ) ) == child2.end() ) {
        child2.at(j) = parent1.at(i);
      } else {
        child2.at(j) = parent1.at(it - child2.begin() );
      }
    }
  }
  result.push_back( IntegerIndividual(child2) );
  result.push_back( IntegerIndividual(child1) );
  return result;
}

std::vector < IntegerIndividual > 
IntegerIndividual::partiallyMappedCrossover (IntegerIndividual spouse) {
  size_t a = rand() % chromosome.size(), b = rand() % chromosome.size();
  while ( a == b ) {
    b = rand() % chromosome.size();
  }
  size_t t = a;
  a = a<b?a:b;
  b = b<t?t:b;
  std::cout << "Puntos de cruza: " << a << ":"<< b << std::endl;
  return partiallyMappedCrossover( spouse, a, b );
}

std::vector < IntegerIndividual > 
IntegerIndividual::positionBasedCrossover (IntegerIndividual spouse, std::set < int > index) {
  std::vector < IntegerIndividual > result;
  std::vector < int > parent1 = getChromosome();
  std::vector < int > parent2 = spouse.getChromosome();
  std::vector < int > child1(parent1.size(),-1), child2(parent2.size(),-1);
  for(size_t i : index) {
    child1.at(i) = parent1.at(i);
    child2.at(i) = parent2.at(i);
  }
  std::vector <int>::iterator itp1 = parent1.begin(), itp2=parent2.begin(), itc1=child1.begin(), itc2=child2.begin();
  while( itc1 != child1.end() ) {
    if ( *itc1 == -1 ) {
      if ( std::find(child1.begin(),child1.end(),*itp2) == child1.end() ) {
        *itc1 = *itp2;
        itc1++;
      }
      itp2++;
    } else {
      itc1++;
    }
  }
  while( itc2 != child2.end() ) {
    if ( *itc2 == -1 ) {
      if ( std::find(child2.begin(),child2.end(),*itp1) == child2.end() ) {
        *itc2 = *itp1;
        itc2++;
      }
      itp1++;
    } else {
      itc2++;
    }
  }
  result.push_back( IntegerIndividual(child1) );
  result.push_back( IntegerIndividual(child2) );
  return result;
}

std::vector < IntegerIndividual > 
IntegerIndividual::positionBasedCrossover (IntegerIndividual spouse) {
  std::set < int > points;
  do {
    points.insert (rand () % 10);
  } while (points.size() < 4);
  std::cout << "Posiciones: ";
  for(int i : points){
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return positionBasedCrossover(spouse, points);
}

std::vector < IntegerIndividual > 
IntegerIndividual::orderBasedCrossover (IntegerIndividual spouse, std::set < int > index) {
  std::vector < IntegerIndividual > result;
  std::vector < int > parent1 = getChromosome();
  std::vector < int > parent2 = spouse.getChromosome();
  std::vector < int > child1(parent2), child2(parent1);
  for(std::vector<int>::iterator itc = child1.begin(), itp = parent1.begin(); itc != child1.end() ; ) {
    if( index.find(*itc) != index.end() ){
      if ( index.find(*itp) != index.end() ) {
        *itc = *itp;
        itc++;
      }
      itp++;
    } else {
      itc++;
    }
  }
  for(std::vector<int>::iterator itc = child2.begin(), itp = parent2.begin(); itc != child2.end() ; ) {
    if( index.find(*itc) != index.end() ){
      if ( index.find(*itp) != index.end() ) {
        *itc = *itp;
        itc++;
      }
      itp++;
    } else {
      itc++;
    }
  }
  result.push_back( IntegerIndividual(child1) );
  result.push_back( IntegerIndividual(child2) );
  return result;
}

std::vector < IntegerIndividual > 
IntegerIndividual::orderBasedCrossover (IntegerIndividual spouse) {
  std::set < int > points;
  do {
    points.insert (rand () % 10 + 1);
  } while (points.size() < 4);
  std::cout << "Posiciones: ";
  for(int i : points){
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return orderBasedCrossover(spouse, points);
}

std::vector < IntegerIndividual > 
IntegerIndividual::cycleCrossover (IntegerIndividual spouse, size_t a) {
  std::vector < IntegerIndividual > result;
  std::vector < int > parent1 = getChromosome();
  std::vector < int > parent2 = spouse.getChromosome();
  std::vector < bool > cycle (chromosome.size(), false);
  std::vector < int > child1, child2;
  std::vector < int >::iterator it1,it2;
  int x=parent1.at(a), y=parent2.at(a);
  cycle.at(a) = true;
  for (size_t i = 0; i < chromosome.size(); i++) {
    it1 = std::find(parent1.begin(), parent1.end(), y);
    it2 = std::find(parent2.begin(), parent2.end(), x);
    x = parent1.at( it2 - parent2.begin() );
    y = parent2.at( it1 - parent1.begin() );
    if ( cycle.at( it2 - parent2.begin() ) & cycle.at( it1 - parent1.begin() ) ) {
      break;
    }
    cycle.at( it2 - parent2.begin() ) = true;
    cycle.at( it1 - parent1.begin() ) = true;
  }
  for(size_t i = 0; i<chromosome.size(); i++) {
    if( cycle.at(i) ) {
      child1.push_back( parent1.at(i) );
      child2.push_back( parent2.at(i) );
    } else {
      child1.push_back( parent2.at(i) );
      child2.push_back( parent1.at(i) );
    }
  }
  result.push_back( IntegerIndividual(child1) );
  result.push_back( IntegerIndividual(child2) );
  return result;
}

std::vector < IntegerIndividual > 
IntegerIndividual::cycleCrossover (IntegerIndividual spouse) {
  size_t a = rand() % chromosome.size();
  std::cout << "Ciclo comienza en: " << a << std::endl;
  return cycleCrossover( spouse, a);
}

IntegerIndividual
IntegerIndividual::mut_insercion ( void ) {
  std::vector < int > ch = chromosome;
  int a = rand()%chromosome.size(), b = rand()%chromosome.size(), t;
  t = ch.at(a);
  ch.erase(ch.begin()+a);
  ch.insert(ch.begin()+b,t);
  return IntegerIndividual(ch);
}

IntegerIndividual
IntegerIndividual::mut_desplazamiento ( void ) {
  std::vector < int > ch = chromosome;
  int n = chromosome.size()/3;
  IntegerIndividual t (ch);
  while (n-- > 0) {
    t = t.mut_insercion();
  }
  return t;
}

IntegerIndividual
IntegerIndividual::mut_intercambio_reciproco ( void ) {
  std::vector < int > ch = chromosome;
  int a = rand()%chromosome.size(), b = rand()%chromosome.size(), t;
  t = ch.at(a); 
  ch.at(a) = ch.at(b);
  ch.at(b) = t;
  return IntegerIndividual ( ch );
}

IntegerIndividual
IntegerIndividual::mut_heuristica ( void ) {
  std::vector < int > ch = chromosome;
  std::set < int > val, pos;
  int n = rand()%((ch.size()-1)/2)+2;
  while (n--) {
    int t = rand()%ch.size();
    if( std::find (pos.begin(), pos.end(), t) == pos.end() ) {
      pos.insert(t);
      val.insert( ch.at(t) );
    } else {
      n++;
    }
  }
  /*do {
    valfinal = std::vector < int > (val);
  } while ( std::next_permutation( val.begin(), val.end() ) );*/
  std::set<int>::iterator it = val.end();
  for (int p : pos) {
    it--;
    std::cout << ch.at(p) << " ";
    ch.at(p) = *it;
  }
  std::cout << std::endl;
  return IntegerIndividual(ch);
}
