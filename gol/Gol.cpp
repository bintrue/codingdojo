#include "Gol.hpp"

const CellState Gol::DEAD;
const CellState Gol::LIVE;

Gol::Gol(int width, int height)
: matrix_(width,std::vector<CellState>(height, DEAD))
{
}

int Coordinate(int coord, int size)
{

}

int Gol::getNeighbourCount(int i, int j) const
{
  const MatrixType& tmp = matrix_;
  return tmp[i - 1][j] + 
         tmp[i - 1][j - 1] +
         tmp[i]    [j - 1] +
         tmp[i + 1][j - 1] +
         tmp[i + 1][j] +
         tmp[i + 1][j + 1] +
         tmp[i]    [j + 1] +
         tmp[i - 1][j + 1];
}

