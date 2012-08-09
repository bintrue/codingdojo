#include "Gol.hpp"

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

CellState Gol::getNewState(int x, int y) const
{
  
  if( matrix_[x][y] == DEAD )
  {
    return (getNeighbourCount(x, y) == 3)?ALIVE:DEAD;
  }
  else
  {
    return (getNeighbourCount(x,y) == 3 ||
            getNeighbourCount(x,y) == 2)? ALIVE:DEAD;
  }
}
