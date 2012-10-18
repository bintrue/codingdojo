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

    Result solve(Board&);

  private:
    bool nextValue();
    bool stepForward();
    bool stepBack();
  };
}