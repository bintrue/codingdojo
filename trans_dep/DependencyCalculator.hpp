#pragma once

#include <istream>
#include <iostream>
#include <map>
#include <set>
#include <vector>


class DependencyCalculator
{
  public:
    typedef std::string NodeId;
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
      Graph::const_iterator iter=m_graph.find(id);
      if (iter!=m_graph.end())
      {
        std::copy(iter->second.begin(),iter->second.end(),out);
      }
    }


  private:
    typedef std::map<NodeId,std::vector<NodeId>> Graph;

    Graph m_graph;
};
