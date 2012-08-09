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
    void testFirstGeneration()
    {

      Gol gol( 5, 5 );
      std::stringstream init;
      init << "....." << std::endl;
      init << "..X.." << std::endl;
      init << "..X.." << std::endl;
      init << "..X.." << std::endl;
      init << "....." << std::endl;
      gol.firstGeneration( init );
      
      std::cout << init.str().size() << " -" << init.str() << "-" << std::endl; 
      
//      TS_ASSERT_EQUALS( true, init.str().empty() );

      Gol::MatrixType correct_matrix = 
          {{Gol::DEAD, Gol::DEAD, Gol::DEAD, Gol::DEAD, Gol::DEAD},
           {Gol::DEAD, Gol::DEAD, Gol::DEAD, Gol::DEAD, Gol::DEAD},
           {Gol::DEAD, Gol::ALIVE, Gol::ALIVE, Gol::ALIVE, Gol::DEAD},
           {Gol::DEAD, Gol::DEAD, Gol::DEAD, Gol::DEAD, Gol::DEAD},
           {Gol::DEAD, Gol::DEAD, Gol::DEAD, Gol::DEAD, Gol::DEAD}};

      TS_ASSERT_EQUALS( gol.matrix_, correct_matrix);
    }

    void testEvolve()
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

      std::stringstream init2;
      Gol gol2( 5, 5 );
      init2 << "....." << std::endl;
      init2 << "....." << std::endl;
      init2 << ".XXX." << std::endl;
      init2 << "....." << std::endl;
      init2 << "....." << std::endl;
      gol2.firstGeneration( init2 );
      TS_ASSERT_EQUALS( gol.matrix_, gol2.matrix_ );
    }
    
};

