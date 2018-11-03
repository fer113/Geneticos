#include "individual.h"

Individual::Individual (size_t n, size_t m) {
  for (size_t i = 0; i < n; i++) {
    chromosome.push_back ( Gen (m) );
  }
  for (size_t i = 0; i < (n*m) ; i++) {
    crossPoints.push_back( rand()%10<3?1:0 );
  }
}

Individual::Individual (std::vector < bool > ch, size_t g) {
  size_t n = ch.size()/g;
  std::vector < bool > t;
  for ( size_t i = 0, j = 0; i < ch.size(); i++ ) {
    t.push_back( ch.at(i) );
    j++;
    if (j >= n) {
      j = 0;
      chromosome.push_back( Gen (t) );
      t.clear();
    }
  }
}

int
Individual::getAptitude (void) {
  int result = 0;
  for (size_t i = 0; i < chromosome.size (); i++) {
    result += chromosome.at (i).getValue ();
  }
  return result;
}

std::vector < bool >
Individual::getChromosome (void) {
  std::vector < bool > result;
  for (size_t i = 0; i < chromosome.size (); i++) {
    for (size_t j = 0; j < chromosome.at (i).gen.size(); j++) {
      result.push_back ( chromosome.at(i).gen.at(j) );
    }
  }
  return result;
}

std::string
Individual::getChromosomeString (void) {
  std::string result;
  std::vector < bool > ch = getChromosome();
  for (bool alel : ch) {
    result.push_back ( alel?'1':'0' );
  }
  return result;
}

std::string
Individual::getMarksString (void) {
  std::string result;
  for (bool alel : crossPoints) {
    result.push_back ( alel?'!':'0' );
  }
  return result;
}

std::vector < Individual >
Individual::cruzaUnPunto (Individual& spouse, size_t p) {
  std::vector < Individual > result;
  std::vector < bool > parent1 = getChromosome();
  std::vector < bool > parent2 = spouse.getChromosome();
  std::vector < bool > child1, child2;
  size_t size = parent1.size();
  size_t genNumber = chromosome.size();
  for( size_t i = 0; i < size; i++ ) {
    if (i < p) {
      child1.push_back( parent1.at(i) );
      child2.push_back( parent2.at(i) );
    } else {
      child1.push_back( parent2.at(i) );
      child2.push_back( parent1.at(i) );
    }
  }
  result.push_back( Individual(child1,genNumber) );
  result.push_back( Individual(child2,genNumber) );
  return result;
}

std::vector < Individual >
Individual::cruzaDosPuntos (Individual& spouse, size_t x, size_t y) {
  std::vector < Individual > result;
  std::vector < bool > parent1 = getChromosome();
  std::vector < bool > parent2 = spouse.getChromosome();
  std::vector < bool > child1, child2;
  size_t size = parent1.size();
  size_t genNumber = chromosome.size();
  size_t t = x;
  x = x<y?x:y;
  y = y<t?t:y;
  for( size_t i = 0; i < size; i++ ) {
    if (i < x || i >= y) {
      child1.push_back( parent1.at(i) );
      child2.push_back( parent2.at(i) );
    } else {
      child1.push_back( parent2.at(i) );
      child2.push_back( parent1.at(i) );
    }
  }
  result.push_back( Individual(child1,genNumber) );
  result.push_back( Individual(child2,genNumber) );
  return result;
}

std::vector < Individual >
Individual::cruzaUniforme (Individual& spouse, std::set < int > index) {
  std::vector < Individual > result;
  std::vector < bool > parent1 = getChromosome();
  std::vector < bool > parent2 = spouse.getChromosome();
  std::vector < bool > child1, child2;
  size_t size = parent1.size();
  size_t genNumber = chromosome.size();
  for( size_t i = 0; i < size; i++ ) {
    if ( index.find ( i ) == index.end() ) {
      child1.push_back( parent1.at(i) );
      child2.push_back( parent2.at(i) );
    } else {
      child1.push_back( parent2.at(i) );
      child2.push_back( parent1.at(i) );
    }
  }
  result.push_back( Individual(child1,genNumber) );
  result.push_back( Individual(child2,genNumber) );
  return result;
}

std::vector < Individual >
Individual::cruzaAcentuada (Individual& spouse) {
  std::vector < Individual > result;
  std::vector < bool > parent1 = getChromosome();
  std::vector < bool > parent2 = spouse.getChromosome();
  size_t size = parent1.size();
  size_t genNumber = chromosome.size();
  std::vector < bool > child1_ch, child2_ch, child1_marks(size, false), child2_marks(size, false);
  bool cross = false;
  std::vector <bool>::iterator mark_it = crossPoints.begin();
  std::vector <bool>::iterator mark_spouse_it = spouse.crossPoints.begin();
  for( size_t i = 0; i < size; i++, mark_it++, mark_spouse_it++ ) {
    if (*mark_it || *mark_spouse_it) {
      cross = !cross;
    }
    if(!cross) {
      if(*mark_it) {
        child2_marks.at(i) = true;
      } if (*mark_spouse_it) {
        child1_marks.at(i) = true;
      }
      child1_ch.push_back( parent1.at(i) );
      child2_ch.push_back( parent2.at(i) );
    } else {
      if(*mark_it) {
        child1_marks.at(i) = true;
      } if (*mark_spouse_it) {
        child2_marks.at(i) = true;
      }
      child1_ch.push_back( parent2.at(i) );
      child2_ch.push_back( parent1.at(i) );
    }
  }
  Individual child1 (child1_ch,genNumber);
  Individual child2 (child2_ch,genNumber);
  child1.crossPoints = child1_marks;
  child2.crossPoints = child2_marks;
  result.push_back( child1 );
  result.push_back( child2 );
  return result;
}


Individual
Individual::mutate ( void )
{
  Individual child ( *this );
  //std::cout << "p:" << getChromosomeString() << std::endl;
  for ( size_t i = 0; i < child.chromosome.size(); i++ )
  {
    child.chromosome.at (i).mutate();
  }
  //std::cout << "c:" << child.getChromosomeString() << std::endl;
  return child;
}
