#include "09_algorithms.h"
#include <numeric>

bool
is_palindrome (const std::string_view &s)
{
  return std::equal (s.begin (), s.begin () + s.size () / 2, s.rbegin ());
};


int
simple_accumulate(const std::vector<int>& v){
  return std::accumulate (v.begin (), v.end (), 0);
};

std::string dashed_string(const std::vector<std::string>& s){

  auto dash_fold = [](std::string a, const std::string& b) {
    return std::move(a) + '-' + b;
  };

  return std::accumulate(std::next(s.begin()),
                         s.end(),
                         s[0], // init from 1st pos, thus require begin at 2 (std::next)
                         dash_fold);
};
