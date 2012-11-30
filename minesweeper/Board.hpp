#pragma once

#include <vector>
#include "Node.hpp"

namespace minesweeper
{
  using std::size_t;
  class Board 
  {
  public:
    typedef graph::Node<int> NodeType;

    Board( size_t nodeCount, size_t mineCount );

    size_t nodeCount() const;
    size_t mineCount() const;

    void createNodes(size_t count);
    void setMine(size_t mineNum);

  protected:
    std::vector<NodeType> m_nodes;
  };
}

