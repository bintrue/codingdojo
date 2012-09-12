#include "Board.hpp"
namespace sudoku
{

  size_t Board::size() const
  {
    return m_width * m_height;
  }

  Board::CellType& Board::operator()(size_t x, size_t y)
  {
    return m_board[y*size()+x];
  }
}

