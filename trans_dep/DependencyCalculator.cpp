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
