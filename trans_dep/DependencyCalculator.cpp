#include "DependencyCalculator.hpp"
#include <sstream>
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
  if (m_graph.end() == deps)
  {
    return {};
  }
  beenThere.push_front(nodeId);
  std::vector<NodeId> returnDeps;
  for ( const auto& dep : deps->second){
    if (beenThere.end() == doneThat.find(nodeId))
    {
      returnDeps.append( doTheDependecyCalculationPlease( dep, beenThere, doneThat ));
    }
  }
  assert(beenThere.front() == nodeId);
  beenThere.pop_front();
  doneThat.insert(nodeId);
  return {};
}

