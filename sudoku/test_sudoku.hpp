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
      std::stringstream sstr("3");
      std::istream_iterator<Board::CellType> last;
      Board testBoard{std::istream_iterator<Board::CellType>(sstr),last,1,1};
      TS_ASSERT_EQUALS( testBoard.size(), 1 );
      TS_ASSERT_EQUALS( testBoard(0,0), 3 );
      
      std::vector<Board::CellType> sstrBig{0, 1, 2, 3,  11, 12, 13, 14,  21, 22, 23, 24,  31, 32, 33, 34};
      Board testBoardBig{sstrBig.begin(),sstrBig.end(),2,2};
      TS_ASSERT_EQUALS( testBoardBig.size(), 4 );
      TS_ASSERT_EQUALS( testBoardBig(3,0), 3 );

      for( size_t y=0; y<=3; ++y)
      {
        for ( size_t x=0; x<=3; ++x)
        {
          TS_ASSERT_EQUALS( testBoardBig(x,y), sstrBig[y*testBoardBig.size()+x]);
        }
      }

      std::stringstream sstrThrowLess("0 1 2 3  0 0 0 0  0 0 0 0  0 0 0");
      TS_ASSERT_THROWS(Board(std::istream_iterator<Board::CellType>(sstrThrowLess),last,2,2), std::runtime_error);

      std::stringstream sstrThrowMore("0 1 2 3  0 0 0 0  0 0 0 0  0 0 0 3 1234567890");
      TS_ASSERT_THROWS(Board(std::istream_iterator<Board::CellType>(sstrThrowMore),last,2,2), std::runtime_error);
    }
};

