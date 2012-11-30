#include <cxxtest/TestSuite.h>

#include <string>
#include <functional>
#include "GridBoard.hpp"

class GridBoardTest: public CxxTest::TestSuite
{
  public:

    void test_that_we_can_create_board()
    {
      minesweeper::GridBoard gridBoard(6, 7, 5);
      TS_ASSERT_EQUALS(gridBoard.nodeCount(), 42u);
      TS_ASSERT_EQUALS(gridBoard.mineCount(), 5u);
    }

    void test_check_connectivity()
    {
      minesweeper::GridBoard gridBoard(6, 7, 5);
      gridBoard(1,1);
    }
};

