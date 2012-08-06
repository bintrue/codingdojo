#include <cxxtest/TestSuite.h>

#include "Anagramma.hpp"
#include <algorithm>
#include <sstream>

#include <boost/algorithm/string/split.hpp>

class SampleTest : public CxxTest::TestSuite
{
  std::string test_in;
  public:
    SampleTest()
      : test_in( "te st" )
    {
    }


    void testreturnOne()
    {
      Anagramma anagramma;
      std::vector<std::string> result;

      result = anagramma.generate(test_in);
      TS_ASSERT( !result.empty() );
    }


    void testcheckOrig()
    {
      Anagramma anagramma;
      std::vector<std::string> result;

      result = anagramma.generate(test_in);
      TS_ASSERT_DIFFERS(std::find(result.begin(), result.end(), test_in), result.end());
    }


    void testEmpty()
    {
      Anagramma ana;

      TS_ASSERT_EQUALS(0, ana.generate("").size());
    }


    void testcheckOne()
    {
      Anagramma anagramma;
      std::vector<std::string> result;

      result = anagramma.generate(test_in);
      TS_ASSERT_DIFFERS(std::find(result.begin(), result.end(), "st te"), result.end());
    }


    void testNumberForSimpleText()
    {
      std::string input("abc");
      Anagramma anagramma;
      TS_ASSERT_EQUALS(6, anagramma.generate(input).size());
    }


    void testNumber()
    {
      Anagramma ana;
      int num = 5 * 4 * 3 * 2 * 1 / 2;
      TS_ASSERT_EQUALS(num, ana.generate(test_in).size());
    }


    void testAllUnique()
    {
      Anagramma anagramma;

      std::vector<std::string> result;
      result = anagramma.generate(test_in);
      std::vector<std::string>::iterator itNewEnd;
      std::sort(result.begin(), result.end());
      itNewEnd = std::unique(result.begin(), result.end());
      TS_ASSERT_EQUALS( itNewEnd, result.end());
    }


    void testOutput()
    {
      // Arrange
      Anagramma anagramma;
      std::vector<std::string> result;
      std::stringstream ss;
      std::string in = "\naaa\naa\na\n";
      result = anagramma.generate(in);

      // Act
      const char separator( '\n' );
      anagramma.generate(in, ss, separator );

      // Assert
      std::string strResult( ss.str() );
      const int itLength(in.length() + 1);
      for ( size_t start( 0 ); start < strResult.length(); start+=itLength )
      {
        result.erase( std::remove(begin(result), end(result), strResult.substr( start, itLength - 1 ) ), end(result) );
      }

      TS_ASSERT( result.empty() );

      anagramma.generate(in, std::cout, separator);
    }

};

