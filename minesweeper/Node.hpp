#pragma once

#include <vector>
#include <functional>
namespace graph
{

  template < class Data >
  class Node
  {
    public:

      typedef std::vector<std::reference_wrapper<Node>> Nodes;
      typedef typename Nodes::iterator iterator;

      Node( const Data& data )
        : m_data( data )
      {
      }

      Data& data()
      {
        return m_data;
      }

      void addNeighbour( Node& n)
      {
        m_nodes.push_back(std::ref(n));
      }

      iterator begin()
      {
        return m_nodes.begin();
      }

      iterator end()
      {
        return m_nodes.end();
      }

    private:
      Data m_data;
      Nodes m_nodes;
  };

}

