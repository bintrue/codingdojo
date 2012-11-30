#pragma once

#include <vector>
#include "Board.hpp"

namespace minesweeper
{
  class GridBoard : public Board
  {
    public:
      GridBoard(size_t width, size_t height, size_t mineCount);
      const NodeType& operator()(size_t x, size_t y) const;
  };
}

