#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "08_closure_struct.cpp"


TEST_CASE("testing asd -> 00") {
  CHECK(newslbplus(1,2) == 3);
}
