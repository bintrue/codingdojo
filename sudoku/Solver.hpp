#pragma once

#include "Board.hpp"
#include <stack>
#include <tuple>

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
    struct State
    {
      size_t x;
      size_t y;
    };
    typedef std::stack< State > StateStack;

    Board& m_board;
    StateStack m_stateStack;

    bool nextValue();
    bool stepForward();
    bool stepBack();
  };
}
