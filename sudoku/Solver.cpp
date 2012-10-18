#include <cassert>

#include "Solver.hpp"

namespace sudoku
{
Solver::Solver(Board& board)
  : m_board(board)
{
}


Solver::Result Solver::solve()
{
  m_board(0, 0) = 1;
  stepForward();
  do
  {
    while(nextValue())
    {
      if (m_board.isValid())
      {
        if (!stepForward())
        {
          return Result::SUCCESS;
        }
      }
    }
  }
  while(stepBack());
  return Result::SUCCESS;
}


bool Solver::nextValue()
{
  assert(0 == 1);
  return true;
}


bool Solver::stepForward()
{
  assert(0 == 1);
}

bool Solver::stepBack()
{
  assert(0 == 1);
}

}

