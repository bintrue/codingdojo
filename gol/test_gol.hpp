#include <cxxtest/TestSuite.h>

#define private public

#include "Gol.hpp"

class SampleTest : public CxxTest::TestSuite
{
  public:
    SampleTest()
    {
    }


    void testSample()
    {
      TS_ASSERT_EQUALS( true, true );
    }

    void testLiveNeighbourCountWithBoundaries()
    {
      Gol gol(10,10);
      gol.matrix_[0][0]=1;
      TS_ASSERT_EQUALS( gol.getNeighbourCount(0, 1), 1 );
    }

    void testGetNewState()
    {
      Gol gol(10,10);
      TS_ASSERT_EQUALS( gol.getNewState(0,0), Gol::DEAD );

      gol.matrix_[4][5] = Gol::ALIVE;
      gol.matrix_[5][4] = Gol::ALIVE;

      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::DEAD );

      gol.matrix_[6][5] = Gol::ALIVE;

      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::ALIVE );

      gol.matrix_[6][6] = Gol::ALIVE;

      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::DEAD );

      gol.matrix_[5][5] = Gol::ALIVE;

      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::DEAD );

      gol.matrix_[6][6] = Gol::DEAD;

      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::ALIVE );

    }

};

