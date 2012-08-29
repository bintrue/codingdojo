#include "DependencyCalculator.hpp"
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <cassert>


DependencyCalculator::DependencyCalculator( std::istream &in )
{
  std::string line;
  while ( std::getline(in, line) )
  {
    std::istringstream ss(line);
    NodeId id;
    ss >> id;

    std::copy(std::istream_iterator<NodeId>(ss), 
        std::istream_iterator<NodeId>(), 
        std::back_inserter(m_graph[id])); 

  }
}

std::vector<DependencyCalculator::NodeId>
DependencyCalculator::doTheDependecyCalculationPlease(
    const NodeId& nodeId,
    std::deque<NodeId>& beenThere,
    std::set<NodeId>& doneThat ) const
{
  if (beenThere.end() != std::find(beenThere.begin(), beenThere.end(), nodeId))
  {
    throw std::runtime_error("Circular dependency detected");
  }
  auto deps = m_graph.find(nodeId);
  std::vector<NodeId> returnDeps;
  if (m_graph.end() != deps)
  {
    beenThere.push_front(nodeId);
    for ( const auto& dep : deps->second){
      if (doneThat.end() == doneThat.find(dep))
      {
        std::vector<NodeId> childDeps = doTheDependecyCalculationPlease( dep, beenThere, doneThat );
        std::copy(childDeps.begin(), childDeps.end(), std::back_inserter(returnDeps));
      }
    }
    assert(beenThere.front() == nodeId);
    beenThere.pop_front();
  }
  doneThat.insert(nodeId);
  returnDeps.push_back(nodeId);
  return returnDeps; 
}

