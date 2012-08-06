#pragma once

#include <vector>
#include <string>
#include <ostream>

class Anagramma
{
public:
  std::vector<std::string> generate( const std::string& text );

  void generate(const std::string& text, std::ostream& out, char separator = '\n' );

};

