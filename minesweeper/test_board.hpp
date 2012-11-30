#include <cxxtest/TestSuite.h>

#include <string>
#include <functional>
#include "Board.hpp"

class BoardTest: public CxxTest::TestSuite
{
  public:

    void test_test_we_can_generate_board()
    {
      {
        minesweeper::Board board( 1, 0 );
        TS_ASSERT_EQUALS( board.nodeCount(), 1 );
        TS_ASSERT_EQUALS( board.mineCount(), 0);
      }

      {
        minesweeper::Board board(42, 5);
        TS_ASSERT_EQUALS( board.nodeCount(), 42);
        TS_ASSERT_EQUALS( board.mineCount(), 5);
      }
    }

};

