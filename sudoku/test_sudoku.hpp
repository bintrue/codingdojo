#include <cxxtest/TestSuite.h>
#include <sstream>
#include <iterator>

#include "Board.hpp"

using sudoku::Board;

class SudokuBoardTest : public CxxTest::TestSuite
{
  public:
    SudokuBoardTest()
    {
    }


    void test_board_can_be_properly_initialized_with_input_iterator()
    {
      std::stringstream sstr("0");
      Board testBoard{std::istream_iterator<Board::CellType>(sstr),1,1};
      TS_ASSERT_EQUALS( testBoard.size(), 1 );
    }


};

