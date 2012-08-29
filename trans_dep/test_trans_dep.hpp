#include <cxxtest/TestSuite.h>
#include <sstream>
#include <iterator>
#include "DependencyCalculator.hpp"

class TestDependencyCalculator : public CxxTest::TestSuite
{
  private:
    std::string inBasic = "A B";

  public:
    typedef DependencyCalculator::NodeId NodeId;
    void test_it_should_be_created_by_its_ctor()
    {
      std::stringstream ss(inBasic);
      DependencyCalculator calc(ss);
    }

    void test_getNodeList_should_return_the_nodes()
    {
      std::stringstream ss(inBasic);

      std::set<DependencyCalculator::NodeId> returnedNodes;
      std::set<DependencyCalculator::NodeId> expectedNodes{"A", "B"};


      DependencyCalculator calc(ss);
      calc.getNodeList(std::inserter(returnedNodes, returnedNodes.begin()));

      TS_ASSERT_EQUALS(returnedNodes, expectedNodes);
    }
    
    void test_getDependencies()
    {
      std::stringstream ss(inBasic);

      DependencyCalculator calc(ss);

      std::vector<NodeId> dependencies;
      calc.getDependencies("A", std::back_inserter(dependencies));
      TS_ASSERT_EQUALS(dependencies.size(), 1);
      TS_ASSERT_EQUALS(dependencies[0], "B");
    }
};

