#include "catch.hpp"
#include "../Header.h"
#include "../Board.h"

TEST_CASE("testujemy boarda", "[board]") {
    //Board* board = new Board(1,1);
    //REQUIRE(board->getX()>0);
}

TEST_CASE("testujemy dostep0 w nowym Line1", "[board line reverse]") {
    Line l(1);
    REQUIRE(l[0]);
}

TEST_CASE("GetFromString brd=8x8;", "[board string]") {
    std::string the = "brd=8x8;";
    REQUIRE(GetFromString(the).operator[](0)[0]!=nullptr);
}