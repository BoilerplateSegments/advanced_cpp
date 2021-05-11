#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "00_template.h"
#include "doctest.h"

TEST_CASE("testing template -> 00") {
  CHECK(slbplus(1,2) == 3);
}
