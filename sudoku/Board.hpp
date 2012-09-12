#pragma once 

#include <unistd.h>
#include <vector>

namespace sudoku
{
  class Board
  {
    public:
      typedef int CellType;

      template <class InputIterator>
      Board( InputIterator input, size_t width, size_t height );

      size_t size() const;
      CellType& operator()(size_t x, size_t y);

    private:
      size_t m_width;
      size_t m_height;
      std::vector<CellType> m_board;

  };


  template <class InputIterator>
  Board::Board( InputIterator input, size_t width, size_t height )
    : m_width{ width }
    , m_height{ height }
    , m_board{int(size()*size())}
  {
    for(size_t i=0; i<m_board.size(); ++i)
    {
      m_board[i]=*input++;
    }
  }
  
}

