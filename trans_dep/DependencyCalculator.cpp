#include "DependencyCalculator.hpp"
#include <sstream>
#include <iterator>


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
  return {};
}

