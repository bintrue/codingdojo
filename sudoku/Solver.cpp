#include <cassert>
#include <iostream>
#include "Solver.hpp"

namespace sudoku
{
Solver::Solver(Board& board)
  : m_board(board)
  , m_stateStack()
{
}


Solver::Result Solver::solve()
{
  if (!m_board.isValid())
  {
    return Result::INVALID;
  }
  if (!stepForward())
  {
    return Result::SUCCESS;
  }
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
  return Result::INVALID;
}


bool Solver::nextValue()
{
  assert( ! m_stateStack.empty() );
  State & curr = m_stateStack.top();
  Board::CellType & newValue = m_board(curr.x, curr.y);
  if ( ++newValue > m_board.size() )
  {
    newValue = 0;
    return false;
  }
  return true;
}


bool Solver::stepForward()
{

  for ( size_t y( 0 ); y< m_board.size(); ++y )
  {
    for ( size_t x( 0 ); x< m_board.size(); ++x )
    {
      if ( 0==m_board( x, y ) )
      {
        State newState{ x, y };
        m_stateStack.push( newState );
        return true;
      }
    }
  }

  return false;
}

bool Solver::stepBack()
{
  assert( ! m_stateStack.empty() );
  m_stateStack.pop();
  std::cout<<m_stateStack.size()<<" ";
  if (m_stateStack.size()==1) std::cout<<std::endl;
  return !m_stateStack.empty();
}

}

