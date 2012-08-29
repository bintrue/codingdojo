#include <cxxtest/TestSuite.h>
#include <sstream>
#include <iterator>
#include <algorithm>
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
      auto nodePos = std::find(begin(resultNodes), end(resultNodes), nodeId);
      if (resultNodes.end() == nodePos)
      {
        return true;
      }
      for (const auto& node : toCheck) {
        if (nodePos == std::find(resultNodes.begin(), nodePos, node)) {
          return false;
        }
      }
      return true;
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
      std::copy(resultForA.begin(),resultForA.end(),std::ostream_iterator<NodeId>(std::cout,","));
      TS_ASSERT( isBefore(resultForA, "A", {"B", "C"}));
      TS_ASSERT( isBefore(resultForA, "B", {"D"}));
      TS_ASSERT( isBefore(resultForA, "C", {"E", "F"}));
      TS_ASSERT( isBefore(resultForA, "E", {"B"}));


      TS_ASSERT( isBefore(resultForA, "A", {"B", "C", "D", "E", "F"}));
      TS_ASSERT( isBefore(resultForA, "B", {"D"}));
      TS_ASSERT( isBefore(resultForA, "C", {"B", "D", "E", "F"}));
      TS_ASSERT( isBefore(resultForA, "D", {}));
      TS_ASSERT( isBefore(resultForA, "E", {"B", "D"}));
      TS_ASSERT( isBefore(resultForA, "F", {}));
    }

  void test_getDependencies_fail_for_trivial_cyclic_dependencies()
  {
      std::string trivialCyclic= "A A"; 

      std::stringstream ss(trivialCyclic);

      DependencyCalculator calc(ss);
      NodeId nodeToCheck = "A";
      TS_ASSERT_THROWS(calc.getDependencies(nodeToCheck, std::ostream_iterator<NodeId>(std::cout)),std::runtime_error);
  }

  void test_getDependencies_fail_for_nontrivial_cyclic_dependencies()
  {
      std::string cyclicDep= "A B C\n" 
                              "B D\n"
                              "C E F\n"
                              "E B\n"
                              "E A\n";

      std::stringstream ss(cyclicDep);

      DependencyCalculator calc(ss);
      NodeId nodeToCheck = "A";
      TS_ASSERT_THROWS(calc.getDependencies(nodeToCheck, std::ostream_iterator<NodeId>(std::cout)),std::runtime_error);
  }
};

