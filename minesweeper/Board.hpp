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

    size_t mineCount() const;

    void createNodes(size_t count);
    void setMine(size_t mineNum);

  private:
    typedef graph::Node<int> NodeType;
    std::vector<NodeType> m_nodes;
  };

  Board generateGrid(size_t width, size_t height, size_t mineNum);
}

