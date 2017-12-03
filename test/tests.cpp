#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Header.h"

TEST_CASE("testujemy abs", "[abs]") {
    REQUIRE(abs(-1)==1);
}