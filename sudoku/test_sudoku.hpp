#include <cxxtest/TestSuite.h>
#include <sstream>
using sudoku::Board;

class SudokuBoardTest : public CxxTest::TestSuite
{
  public:
    SudokuBoardTest()
    {
    }


    void testConstruct()
    {
      std::stringstream sstr("0");
      Board testBoard{std::istream_iterator<Board::CellType>(sstr),1,1};
      TS_ASSERT_EQUALS( testBoard.size(), 1 );
    }

};

