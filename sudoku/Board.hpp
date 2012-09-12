#pragma once 

#include <unistd.h>

namespace sudoku
{
  class Board
  {
    public:
      typedef int CellType;

      template <class InputIterator>
      Board( InputIterator input, size_t width, size_t height );

      size_t size() const;

    private:
      size_t m_width;
      size_t m_height;
  };


  template <class InputIterator>
  Board::Board( InputIterator input, size_t width, size_t height )
    : m_width{ width }
    , m_height{ height }
  {
    
  }

}

