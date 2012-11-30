#include <cxxtest/TestSuite.h>

#include <string>
#include <algorithm>
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

    void test_check_operator_with_xy_coords_exists()
    {
      minesweeper::GridBoard gridBoard(6, 7, 5);
        gridBoard(1,1);
    }

    void test_node_connectivity()
    {
      minesweeper::GridBoard gridBoard(6, 7, 5);
      auto &topLeft=gridBoard(0,0);
      auto &topLeftRightNeighbour=gridBoard(1,0);
      TS_ASSERT_DIFFERS(
      std::find_if(topLeft.begin(),topLeft.end(),
          [&] (const minesweeper::GridBoard::NodeType &x)
          {
            return &x==&topLeftRightNeighbour;
          }),
      topLeft.end());
    }

};

