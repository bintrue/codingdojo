#pragma once

#include <vector>
#include <sstream>

typedef char CellState;

class Gol
{
  public:
    const static CellState ALIVE = 1;
    const static CellState DEAD = 0;

    Gol(int width, int height);
    int getNeighbourCount(int x, int y) const;
    void firstGeneration(std::istream&);

    bool evolve();

  private: 
    CellState const& getAt(int x, int y) const;
    typedef std::vector<std::vector<CellState>> MatrixType;
    MatrixType matrix_;
    CellState getNewState(int x, int y) const;
};

