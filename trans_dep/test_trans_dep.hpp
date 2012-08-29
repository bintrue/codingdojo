#include <cxxtest/TestSuite.h>
#include <sstream>
#include <iterator>
#include "DependencyCalculator.hpp"

class TestDependencyCalculator : public CxxTest::TestSuite
{
  public:
    void test_it_should_be_created_by_its_ctor()
    {
      std::string in = "A B";
      std::stringstream ss(in);
      DependencyCalculator calc(ss);
    }

    void test_getNodeList_should_return_the_nodes()
    {
      std::string in = "A B";
      std::stringstream ss(in);

      std::set<DependencyCalculator::NodeId> returnedNodes;
      std::set<DependencyCalculator::NodeId> expectedNodes{"A", "B"};


      DependencyCalculator calc(ss);
      calc.getNodeList(std::inserter(returnedNodes, returnedNodes.begin()));

      TS_ASSERT_EQUALS(returnedNodes, expectedNodes);
    }
};

