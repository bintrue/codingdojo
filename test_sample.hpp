#include <cxxtest/TestSuite.h>

#include "samplecode.hpp"

class SampleTest : public CxxTest::TestSuite
{
  public:
    void testreturnOne()
    {
      TS_ASSERT_EQUALS( return_one(), 1 );
    }
};

