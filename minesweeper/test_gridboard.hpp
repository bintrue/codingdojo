#include <cxxtest/TestSuite.h>

#include <string>
#include <functional>
#include "GridBoard.hpp"

class GridBoardTest: public CxxTest::TestSuite
{
  public:

    void test_that_we_can_create_board()
    {
      minesweeper::GridBoard gridBoard;
    }
};

