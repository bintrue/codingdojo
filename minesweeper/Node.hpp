#pragma once

#include <vector>

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

      void addNeighbour( Node& )
      {

      }

      iterator begin()
      {
        return iterator();
      }

      iterator end()
      {
        return iterator();
      }

    private:
      Data m_data;
  };

}

