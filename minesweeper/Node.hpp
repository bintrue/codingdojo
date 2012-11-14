#pragma once

namespace graph
{

  template < class Data >
  class Node
  {
    public:
      Node( const Data& )
      {
      }

      Data& data()
      {
        static Data data( 42 );
        return data;
      }
  };

}

