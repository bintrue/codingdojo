#include <cxxtest/TestSuite.h>

#include <string>
#include <functional>
#include "Node.hpp"

class NodeTest: public CxxTest::TestSuite
{
  public:
    void test_that_we_can_create_graph_nodes()
    {
      graph::Node< int > ourFirstNode( 42 );
      TS_ASSERT_EQUALS( ourFirstNode.data(), 42 );

      graph::Node< int > ourSecondNode( 43 );
      TS_ASSERT_EQUALS( ourSecondNode.data(), 43 );

      graph::Node< std::string > ourThirdNode( "42" );
      TS_ASSERT_EQUALS( ourThirdNode.data(), std::string( "42" ) );
    }

    void test_that_we_can_add_neighbours()
    {
      graph::Node< int > ourFirstNode( 1 );
      graph::Node< int > ourSecondNode( 2 );
      ourFirstNode.addNeighbour( ourSecondNode );
      TS_ASSERT_EQUALS( &(ourFirstNode.begin()->get()), &ourSecondNode);
      TS_ASSERT_EQUALS( ++(ourFirstNode.begin()), ourFirstNode.end());
    }

};

