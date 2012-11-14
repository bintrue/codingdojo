#include <cxxtest/TestSuite.h>

#include <string>
#include <functional>
#include "Board.hpp"

class BoardTest: public CxxTest::TestSuite
{
  public:

    void test_that_we_can_create_board()
    {
      minesweeper::Board ourFirstBoard;
    }
    void test_test_we_can_generate_board()
    {
      {
        minesweeper::Board gridBoard(minesweeper::generateGrid(1, 1, 0));
        TS_ASSERT_EQUALS(gridBoard.nodeCount(), 1);
      }

      {
        minesweeper::Board gridBoard(minesweeper::generateGrid(6, 7, 5));
        TS_ASSERT_EQUALS(gridBoard.nodeCount(), 42);
        TS_ASSERT_EQUALS(gridBoard.mineCount(), 5);
      }
    }

};

