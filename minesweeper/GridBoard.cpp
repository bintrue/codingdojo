#include "Board.hpp"
#include "GridBoard.hpp"

minesweeper::GridBoard::GridBoard(size_t width, size_t height, size_t mineCount)
: Board( width * height, mineCount)
{
}

const minesweeper::GridBoard::NodeType& minesweeper::GridBoard::operator()(size_t x, size_t y) const
{
  ++x;
  ++y;
  return m_nodes[0];
}
