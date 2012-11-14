#include "Board.hpp"
#include <algorithm>

minesweeper::Board::Board()
{}

void minesweeper::Board::createNodes(size_t count)
{
  m_nodes.resize(count,NodeType(0)); 
}

minesweeper::size_t
minesweeper::Board::mineCount() const
{
  return std::count_if( m_nodes.begin(), m_nodes.end(), [](const NodeType & node)
  {
    return node.data() == 1;
  });
}

minesweeper::Board minesweeper::generateGrid(size_t width, size_t height, size_t mineNum)
{
  Board board;
  board.createNodes(width*height);
  board.setMine(mineNum);
  return board;
}

void minesweeper::Board::setMine(size_t mineNum)
{
  for(size_t i = 0; i < mineNum; ++i)
  {
    m_nodes[i].data() = 1;
  }
}


