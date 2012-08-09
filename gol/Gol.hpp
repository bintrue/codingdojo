#pragma once

#include <vector>

typedef char CellState;

class Gol
{
  public:
    Gol(int width, int height);
  
    int getNeighbourCount(int x, int y) const;
  
  private: 
      std::vector<std::vector<CellState>> matrix_;
};



