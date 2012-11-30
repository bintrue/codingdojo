#include "Board.hpp"
#include <algorithm>

minesweeper::Board::Board( size_t nodeCount, size_t mineCount )
{
  createNodes( nodeCount );
  setMine( mineCount );
}

void minesweeper::Board::createNodes(size_t count)
{
  m_nodes.resize(count,NodeType(0));
}


size_t minesweeper::Board::nodeCount() const
{
  return m_nodes.size();
}


minesweeper::size_t
minesweeper::Board::mineCount() const
{
  return std::count_if( m_nodes.begin(), m_nodes.end(), [](const NodeType & node)
  {
    return node.data() == 1;
  });
}


void minesweeper::Board::setMine(size_t mineNum)
{
  for(size_t i = 0; i < mineNum; ++i)
  {
    m_nodes[i].data() = 1;
  }
}


