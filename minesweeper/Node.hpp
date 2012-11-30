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

      const Data& data() const
      {
        return m_data;
      }

      void addNeighbour( Node& n)
      {
        m_neighbours.push_back(std::ref(n));
      }

      iterator begin()
      {
        return m_neighbours.begin();
      }

      iterator end()
      {
        return m_neighbours.end();
      }

    private:
      Data m_data;
      Nodes m_neighbours;
  };

}

