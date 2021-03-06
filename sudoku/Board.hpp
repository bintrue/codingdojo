#pragma once 

#include <unistd.h>
#include <vector>
#include <stdexcept>
#include <algorithm>

namespace sudoku
{
  class Board
  {
    public:
      class InvalidSizeException {};
      class InvalidValueException {};

      typedef unsigned int CellType;


      template <class InputIterator>
        Board( InputIterator first, InputIterator last, size_t width, size_t height );

      size_t size() const;
      CellType& operator()(size_t x, size_t y);

      bool isValid() const;

      bool isSolved() const;

    private:
      typedef std::vector<CellType> CellContainer;
      CellContainer getRow(size_t row) const;
      CellContainer getColumn(size_t column) const;
      CellContainer getRow(size_t x, size_t y) const;
      CellContainer getColumn(size_t x, size_t y) const;
      CellContainer getBox(size_t box) const;
      CellContainer getBox(size_t x, size_t y) const;

      static bool isValid(CellContainer const & cell);
      size_t m_width;
      size_t m_height;
      CellContainer m_board;

  };


  template <class InputIterator>
    Board::Board( InputIterator first, InputIterator last, size_t width, size_t height )
    : m_width{ width }
  , m_height{ height }
  , m_board(first, last)
  {
    if (m_board.size() != size() * size()) 
    {
      throw InvalidSizeException();
    }
    bool allOf{std::all_of(begin(m_board), end(m_board), [this](CellType value)
        {return value <= CellType(this->size());})
    };
    if (!allOf)
    {
      throw InvalidValueException();
    }
  }
}

