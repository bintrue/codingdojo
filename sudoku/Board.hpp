#pragma once 

#include <unistd.h>
#include <vector>
#include <stdexcept>
#include <sstream>

namespace sudoku
{
  class Board
  {
    public:
      typedef int CellType;

      template <class InputIterator>
      Board( InputIterator first, InputIterator last, size_t width, size_t height );

      size_t size() const;
      CellType& operator()(size_t x, size_t y);

    private:
      size_t m_width;
      size_t m_height;
      std::vector<CellType> m_board;

  };


  template <class InputIterator>
  Board::Board( InputIterator first, InputIterator last, size_t width, size_t height )
    : m_width{ width }
    , m_height{ height }
    , m_board(first, last)
  {
    std::cout << "boardsize: " << m_board.size() << std::endl;
    if (m_board.size() != size() * size()) {
      std::ostringstream ss;
      ss << "Invalid input size: " << m_board.size();
      throw std::runtime_error(ss.str());
    }
  }
  
}

