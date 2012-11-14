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

    size_t nodeCount() const
    {
      return m_nodes.size();
    }

    void createNodes(size_t count);

  private:
    std::vector<graph::Node<int>> m_nodes;
  };

  Board generateGrid(size_t width, size_t height, size_t mineNum);
}

