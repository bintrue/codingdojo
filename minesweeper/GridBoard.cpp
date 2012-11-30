#include "Board.hpp"
#include "GridBoard.hpp"
#include <cassert>

minesweeper::GridBoard::GridBoard(size_t width, size_t height, size_t mineCount)
  : Board( width * height, mineCount)
  , m_width( width )
  , m_height( height)
{
}

const minesweeper::GridBoard::NodeType& minesweeper::GridBoard::operator()(size_t x, size_t y) const
{
  assert( x < m_width);
  assert( y < m_height);
  return m_nodes[m_width*y+x];
}

std::size_t minesweeper::GridBoard::width() const
{
  return m_width;
}

std::size_t minesweeper::GridBoard::height() const
{
  return m_height;
}
