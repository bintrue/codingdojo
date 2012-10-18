#pragma once

#include "Board.hpp"

namespace sudoku
{
  class Solver
  {
  public:
    enum class Result
    {
      SUCCESS,
      INVALID,
      MULTIPLE_SOLUTION
    };

    Solver(Board& board);
    Result solve();

  private:
    Board& m_board;

    bool nextValue();
    bool stepForward();
    bool stepBack();
  };
}
