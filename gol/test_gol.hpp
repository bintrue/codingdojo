#include <cxxtest/TestSuite.h>

#define private public

#include "Gol.hpp"
#include <sstream>

class SampleTest : public CxxTest::TestSuite
{
  public:
    SampleTest()
    {
    }


    void testSample()
    {
      TS_ASSERT_EQUALS( true, true );
    }

    void testLiveNeighbourCountWithBoundaries()
    {
      Gol gol(10,10);
      gol.matrix_[0][0]=1;
      TS_ASSERT_EQUALS( gol.getNeighbourCount(0, 1), 1 );
    }

    void testGetNewState()
    {
      Gol gol(10,10);
      TS_ASSERT_EQUALS( gol.getNewState(0,0), Gol::DEAD );

      gol.matrix_[4][5] = Gol::ALIVE;
      gol.matrix_[5][4] = Gol::ALIVE;
      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::DEAD );

      gol.matrix_[6][5] = Gol::ALIVE;
      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::ALIVE );

      gol.matrix_[6][6] = Gol::ALIVE;
      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::DEAD );

      gol.matrix_[5][5] = Gol::ALIVE;
      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::DEAD );

      gol.matrix_[6][6] = Gol::DEAD;
      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::ALIVE );

      gol.matrix_[6][5] = Gol::DEAD;
      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::ALIVE );

      gol.matrix_[4][5] = Gol::DEAD;
      TS_ASSERT_EQUALS( gol.getNewState(5,5), Gol::DEAD);
    }

    void testReadFile()
    {
      Gol gol( 5, 5 );
      std::stringstream init;
      init << "....." << std::endl;
      init << "..X.." << std::endl;
      init << "..X.." << std::endl;
      init << "..X.." << std::endl;
      init << "....." << std::endl;
      gol.firstGeneration( init );
      TS_ASSERT_EQUALS( true, gol.evolve() );

      TS_ASSERT_EQUALS( true, init.str().empty() );
      Gol gol2( 5, 5 );
      init << "....." << std::endl;
      init << "....." << std::endl;
      init << ".XXX." << std::endl;
      init << "....." << std::endl;
      init << "....." << std::endl;
      gol.firstGeneration( init );
      TS_ASSERT_EQUALS( gol.matrix_, gol2.matrix_ );
    }

    void testEvolve()
    {
    }

};

