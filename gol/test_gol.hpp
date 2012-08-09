#include <cxxtest/TestSuite.h>

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

    void testLiveNeighbourCount()
    {
      Gol gol(10,10);
      gol.matrix_[1][3]=1;
      TS_ASSERT_EQUALS( gol.getNeighbourCount(2, 3), 1 );
    }

};

