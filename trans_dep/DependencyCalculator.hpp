#pragma once
#include <istream>

class DependencyCalculator
{
  public:
    DependencyCalculator( std::istream & );

    template<class OutputIterator>
    void getNodeList( OutputIterator oIt)
    {
      *oIt++ = "A";
      *oIt = "B";
    }

    typedef std::string NodeId;

  private:
    typedef std::map<NodeId,std::vector<NodeId>> Graph;

    Graph m_graph;
};
