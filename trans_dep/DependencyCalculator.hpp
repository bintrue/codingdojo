#pragma once
#include <istream>

class DependencyCalculator
{
  public:
    DependencyCalculator( std::istream & );

    template<class OutputIterator>
    void getNodeList( OutputIterator &);

    typedef std::string NodeId;
};
