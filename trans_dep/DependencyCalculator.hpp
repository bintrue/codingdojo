#pragma once

#include <istream>
#include <map>
#include <set>
#include <vector>


class DependencyCalculator
{
  public:
    DependencyCalculator( std::istream & );

    template<class OutputIterator>
    void getNodeList( OutputIterator output ) const
    {
      std::set<NodeId> nodeList;
      for ( const auto& i : m_graph )
      {
        nodeList.insert( i.first );
        std::copy(
            i.second.begin(), i.second.end(),
            std::inserter( nodeList, std::begin( nodeList ) ) );
      }

      std::copy( nodeList.begin(), nodeList.end(), output );
    }
    
    template <class OutputIterator>
    void getDependencies(const NodeId& id, OutputIterator out) const
    {
      
    }

    typedef std::string NodeId;

  private:
    typedef std::map<NodeId,std::vector<NodeId>> Graph;

    Graph m_graph;
};
