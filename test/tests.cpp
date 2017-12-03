#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Header.h"

TEST_CASE("testujemy abs", "[abs]") {
    REQUIRE(abs(-1)==1);
    //REQUIRE(abs(-2)==1);
}

TEST_CASE("testujemy figury", "[fig]") {
    Figure* pawn = new Pawn(WHITE);
    REQUIRE(pawn->figureDMG>0);
}