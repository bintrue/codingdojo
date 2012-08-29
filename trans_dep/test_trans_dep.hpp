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

    void test_getDependencies_for_non_existing_node()
    {
      std::stringstream ss(inBasic);

      DependencyCalculator calc(ss);

      std::vector<NodeId> dependencies;
      calc.getDependencies("Q", std::back_inserter(dependencies));
      TS_ASSERT(dependencies.empty());
    }

    bool isBefore(const std::vector<NodeId>& resultNodes,
                  const NodeId& nodeId,
                  const std::vector<NodeId>& toCheck ) const
    {
      if (resultNodes.end() == resultNodes.find(nodeId))
      {
        return true;
      }

    }

    void test_getDependencies_for_complex_graph()
    {
      std::string complexIn = "A B C\n" 
                              "B D\n"
                              "C E F\n"
                              "E B\n";

      std::stringstream ss(complexIn);

      DependencyCalculator calc(ss);

      std::vector<NodeId> resultForA;
      NodeId nodeToCheck = "A";

      calc.getDependencies(nodeToCheck, std::back_inserter(resultForA));

      resultForA.push_back(nodeToCheck);
      TS_ASSERT( isBefore(resultForA, "A", {"B", "C", "D", "E", "F"}));
      TS_ASSERT( isBefore(resultForA, "B", {"D"}));
      TS_ASSERT( isBefore(resultForA, "C", {"B", "D", "E", "F"}));
      TS_ASSERT( isBefore(resultForA, "D", {}));
      TS_ASSERT( isBefore(resultForA, "E", {"B", "D"}));
      TS_ASSERT( isBefore(resultForA, "F", {}));

    }
};

