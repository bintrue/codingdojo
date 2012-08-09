#pragma once

#include <vector>

typedef char CellState;

class Gol
{
  public:
    const static CellState ALIVE = 1;
    const static CellState DEAD = 0;

    Gol(int width, int height);

    int getNeighbourCount(int x, int y) const;

  private: 
    CellState const& getAt(int x, int y) const;
    typedef std::vector<std::vector<CellState>> MatrixType;
    MatrixType matrix_;
};



