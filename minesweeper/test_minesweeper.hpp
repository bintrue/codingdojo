#include <cxxtest/TestSuite.h>

#include "Node.hpp"

class GraphTest : public CxxTest::TestSuite
{
  public:
    GraphTest()
    {
    }


    void test_that_we_can_create_graph_nodes()
    {
      graph::Node< int > ourFirstNode( 42 );
      TS_ASSERT_EQUALS( ourFirstNode.data(), 42 );
    }

};

