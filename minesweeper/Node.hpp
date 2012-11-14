#pragma once

namespace graph
{

  template < class Data >
  class Node
  {
    public:
      Node( const Data& data )
        : m_data( data )
      {
      }

      Data& data()
      {
        return m_data;
      }

    private:
      Data m_data;
  };

}

