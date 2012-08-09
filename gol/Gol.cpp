#include "Gol.hpp"

#include <assert.h>

const CellState Gol::DEAD;
const CellState Gol::ALIVE;

  Gol::Gol(int width, int height)
: matrix_(width,std::vector<CellState>(height, DEAD))
{
}

CellState const& Gol::getAt(int i, int j) const
{
  return matrix_[(i + matrix_.size()) % matrix_.size()]
    [(j + matrix_[0].size()) % matrix_[0].size()];
}

int Gol::getNeighbourCount(int i, int j) const
{
  return getAt(i - 1,j) + 
    getAt(i - 1,j - 1) +
    getAt(i    ,j - 1) +
    getAt(i + 1,j - 1) +
    getAt(i + 1,j) +
    getAt(i + 1,j + 1) +
    getAt(i    ,j + 1) +
    getAt(i - 1,j + 1);
}

void Gol::firstGeneration(std::istream& in)
{
  std::string line;
  size_t y = 0;
  while (std::getline(in, line)) {
    size_t x = 0;
    assert (!matrix_.empty() && (matrix_[0].size() > y));
    for (auto i = line.begin(); i != line.end(); ++i, ++x) {
      assert(x < matrix_.size());
      matrix_[x][y] = (*i == 'X') ? ALIVE : DEAD;      
    }
    ++y;
  }
  
}

CellState Gol::getNewState(int x, int y) const
{

  if( matrix_[x][y] == DEAD )
  {
    return (getNeighbourCount(x, y) == 3)?ALIVE:DEAD;
  }

  return (getNeighbourCount(x,y) == 3 ||
      getNeighbourCount(x,y) == 2)? ALIVE:DEAD;
}

bool Gol::evolve()
{
  return true;
}
