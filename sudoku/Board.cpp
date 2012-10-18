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
    for (auto i = 0u; i != size(); ++i)
    {
      if ( !isValid(getRow(i)) ||
           !isValid(getColumn(i)) ||
           !isValid(getBox(i)) )
      {
        return false;
      }
    }
    return true;
  }

  Board::CellContainer Board::getRow(size_t, size_t y) const
  {
    return getRow(y);
  }

  Board::CellContainer Board::getRow(size_t row) const
  {
    return CellContainer(m_board.begin()+size()*row,m_board.begin()+size()*(row+1));
  }
  Board::CellContainer Board::getColumn(size_t x, size_t) const
  {
    return getColumn(x);
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

  Board::CellContainer Board::getBox(size_t x, size_t y) const
  {
    CellContainer ret;
    ret.reserve(size());
   
    x -= x % m_width;
    y -= y % m_height;

    for (auto i(0u); i < m_height; ++i)
    {
      std::copy(m_board.begin() + x + (i + y)* size(),
    		m_board.begin() + x + (i + y) * size() + m_width,
    		std::back_inserter(ret));
    }
    
    return ret;
  }


  Board::CellContainer Board::getBox(size_t box) const
  {
    return getBox((box % m_height) * m_width, 
                  (box / m_height) * (m_height));
  }
  
  bool Board::isValid(CellContainer const & group)
  {
    std::vector<int> count(group.size(),0);
    for(auto cell:group)
    {
      if (cell!=0 && count[cell-1]++ >0 )
      {
        return false;
      }
    }
    return true;
  }


  bool Board::isSolved() const
  {
    bool valid = isValid();
    bool nonZero = ( m_board.end() == std::find(m_board.begin(), m_board.end(), 0));
    return valid && nonZero;

  }
}

