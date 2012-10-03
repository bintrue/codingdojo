#include <cxxtest/TestSuite.h>
#include <sstream>
#include <iterator>
#define private public 
#include "Board.hpp"
#undef private


using sudoku::Board;

class SudokuBoardTest : public CxxTest::TestSuite
{
  public:
    SudokuBoardTest()
    {
    }

    void test_board_can_be_properly_initialized_with_input_iterator()
    {
      std::stringstream sstr("1");
      std::istream_iterator<Board::CellType> last;
      Board testBoard{std::istream_iterator<Board::CellType>(sstr),last,1,1};
      TS_ASSERT_EQUALS( testBoard.size(), 1 );
      TS_ASSERT_EQUALS( testBoard(0,0), 1 );

      std::vector<Board::CellType> sstrBig{0, 1, 2, 3,  1, 2, 3, 4,  1, 2, 3, 4,  1, 2, 3, 4};
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
      TS_ASSERT_THROWS(Board(std::istream_iterator<Board::CellType>(sstrThrowLess),last,2,2), Board::InvalidSizeException);

      std::stringstream sstrThrowMore("0 1 2 3  0 0 0 0  0 0 0 0  0 0 0 3 1234467670");
      TS_ASSERT_THROWS(Board(std::istream_iterator<Board::CellType>(sstrThrowMore),last,2,2), Board::InvalidSizeException);
    }

    void test_board_can_only_be_initialized_with_valid_values()
    {
      std::vector<Board::CellType> vec{0, 1, 2, 3,  11, 12, 13, 14,  21, 22, 23, 24,  31, 32, 33, 34};
      TS_ASSERT_THROWS(Board(vec.begin(), vec.end(), 2, 2), Board::InvalidValueException);
    }
    

    void test_board_getRow_function_works()
    {
      std::vector<Board::CellType> sstrBig{0, 1, 2, 3,  2, 2, 1, 1,  1, 4, 3, 2,  4, 4, 4, 4};

      Board testBoardBig{sstrBig.begin(),sstrBig.end(),2,2};
 //     TS_ASSERT_EQUALS(testBoardBig.getRow(0,1), (Board::CellContainer{2, 2, 1, 1}));
 //     TS_ASSERT_EQUALS(testBoardBig.getRow(0,0), (Board::CellContainer{0, 1, 2, 3}));
      TS_ASSERT_EQUALS(testBoardBig.getRow(1), (Board::CellContainer{2, 2, 1, 1}));
      TS_ASSERT_EQUALS(testBoardBig.getRow(0), (Board::CellContainer{0, 1, 2, 3}));
    }

    void test_board_getColumn_function_works()
    {
      std::vector<Board::CellType> sstrBig{0, 1, 2, 3,  2, 2, 1, 1,  1, 4, 3, 2,  4, 4, 4, 4};

      Board testBoardBig{sstrBig.begin(),sstrBig.end(),2,2};
      TS_ASSERT_EQUALS(testBoardBig.getColumn(1), (Board::CellContainer{1, 2, 4, 4}));
 //     TS_ASSERT_EQUALS(testBoardBig.getColumn(1, 0), (Board::CellContainer{1, 2, 4, 4}));
    }

    void test_board_getBox_function_works()
    {
      std::vector<Board::CellType> sstrBig{0, 1, 2, 3,  2, 2, 1, 1,  1, 4, 3, 2,  4, 4, 4, 4};

      Board testBoardBig{sstrBig.begin(),sstrBig.end(),2,2};
      TS_ASSERT_EQUALS(testBoardBig.getBox(1), (Board::CellContainer{2, 3, 1, 1}));
//      TS_ASSERT_EQUALS(testBoardBig.getBox(1,1), (Board::CellContainer{2, 3, 1, 1}));
    }


    void _test_if_board_is_valid()
    {
      Board::CellType brd[] = { 1 };
      Board easyBoard(&brd[0], &brd[1], 1, 1);
      TS_ASSERT( easyBoard.isValid() );
    }

};

