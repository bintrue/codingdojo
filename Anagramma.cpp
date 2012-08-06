#include "Anagramma.hpp"

#include <algorithm>
#include <iterator>

std::vector<std::string> Anagramma::generate( const std::string& text )
{
  std::vector<std::string> result;
  if (0 == text.length())
  {
    return result;
  }
  std::string tmp(text);
  std::sort(tmp.begin(), tmp.end());

  do {
    result.push_back(tmp);
  }
  while (std::next_permutation(tmp.begin(), tmp.end()));

  return result;
}


void Anagramma::generate(const std::string& text, std::ostream& out, const char separator )
{
  auto result = generate(text);
  char separator_cstr[] = { separator, 0 };

  std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(out, separator_cstr ));
}

