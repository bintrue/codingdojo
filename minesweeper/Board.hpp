#pragma once

#include <vector>
#include "Node.hpp"

namespace minesweeper
{
  using std::size_t;
  class Board 
  {
    public:
      Board();
  };

  Board generateGrid(size_t width, size_t height, size_t mineNum);
}

