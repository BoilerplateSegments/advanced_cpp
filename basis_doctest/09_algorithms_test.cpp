#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "09_algorithms.cpp"

TEST_CASE("testing template -> 00") {
  CHECK(is_palindrome("saippuakivikauppias") == true);
  CHECK(is_palindrome("longest")==false);
  CHECK(simple_accumulate(std::vector<int> {1,2,3}) == 6);
  CHECK(dashed_string (std::vector<std::string> {"a","b","c"}) == "a-b-c");
}
