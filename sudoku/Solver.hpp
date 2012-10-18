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
    typedef std::tuple<std::size_t,std::size_t> Coordinate;
    typedef std::stack< Coordinate > m_stateStack;

    bool nextValue();
    bool stepForward();
    bool stepBack();
  };
}
