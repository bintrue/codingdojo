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
      typedef typename Nodes::const_iterator const_iterator;

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

      const_iterator begin() const
      {
        return m_neighbours.begin();
      }

      const_iterator end() const
      {
        return m_neighbours.end();
      }

    private:
      Data m_data;
      Nodes m_neighbours;
  };

}

