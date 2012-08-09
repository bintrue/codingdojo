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

};

