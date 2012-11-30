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
      TS_ASSERT_EQUALS(gridBoard.width(), 6);
      TS_ASSERT_EQUALS(gridBoard.height(), 7);
    }

    void test_check_operator_with_xy_coords_exists()
    {
      minesweeper::GridBoard gridBoard(6, 7, 5);
        gridBoard(1,1);
    }

    bool isNeighbour(const minesweeper::GridBoard::NodeType &node, 
                     const minesweeper::GridBoard::NodeType &neighbour)
    {
      return hasEdgeTo(node, neighbour) &&
             hasEdgeTo(neighbour, node);
    }
    bool hasEdgeTo(const minesweeper::GridBoard::NodeType &source, 
                   const minesweeper::GridBoard::NodeType &target)
    {
      return(std::find_if(source.begin(),source.end(),
          [&] (const minesweeper::GridBoard::NodeType &x)
          {
            return &x==&target;
          }) != source.end());
    }

    void test_node_top_left_connectivity()
    {
      minesweeper::GridBoard gridBoard(6, 7, 5);
      auto &topLeft=gridBoard(0,0);
      auto &topLeftRightNeighbour=gridBoard(1,0);
      TS_ASSERT(isNeighbour(topLeft, topLeftRightNeighbour));
    }

    void checkNeighbours(minesweeper::GridBoard gridBoard, size_t x, size_t y)
    {
      for( size_t cx = 0; cx < gridBoard.width(); ++cx )
      {
        for( size_t cy = 0; cy < gridBoard.height(); ++ cy )
        {
          bool areNeighbours = abs(x - cx) + abs(y - cy) == 1 ||
                               ( abs(x - cx) == 1 && abs(y - cy) == 1 );
          TS_ASSERT_EQUALS( hasEdgeTo(gridBoard(x,y), gridBoard(cx,cy)),
                            areNeighbours );;
        }
      }
    }

    void test_node_connectivity()
    {
      minesweeper::GridBoard gridBoard( 3, 4, 2 );
      for( size_t x = 0; x < gridBoard.width(); ++x )
      {
        for( size_t y = 0; y < gridBoard.height(); ++y )
        {
          checkNeighbours(gridBoard, x, y);
        }
      }

    }

};

