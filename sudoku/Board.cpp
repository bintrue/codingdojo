#include "Board.hpp"

#include <iterator>

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

  Board::CellContainer Board::getRow(size_t x, size_t y) const
  {
    return CellContainer(m_board.begin()+size()*y,m_board.begin()+size()*(y+1));
  }

  Board::CellContainer Board::getRow(size_t row) const
  {
    return CellContainer(m_board.begin()+size()*row,m_board.begin()+size()*(row+1));
  }

  Board::CellContainer Board::getColumn(size_t col) const
  {
    CellContainer ret;
    ret.reserve(size());
    for ( auto it = m_board.begin()+col; it < m_board.end(); it += size() )
    {
      ret.push_back( *it );
    }
    return ret;
  }

  Board::CellContainer Board::getBox(size_t box) const
  {
    CellContainer ret;
    ret.reserve(size());
    
    int topLeft = (box % m_height) * m_width + (box / m_height) * (m_height * size());
    for (auto i(0u); i < m_height; ++i)
    {
      std::copy(m_board.begin() + topLeft + i * size(),
    		m_board.begin() + topLeft + i * size() + m_width,
    		std::back_inserter(ret));
    }
    
    return ret;
  }

}

