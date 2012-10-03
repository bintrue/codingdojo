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

  bool Board::isValid() const
  {
    return false; 
  }

  Board::CellContainer Board::getRow(int row) const
  {
    return CellContainer(m_board.begin()+size()*row,m_board.begin()+size()*(row+1));
  }

}

