//
// Created by Filip Gulan on 01/01/2018.
//

#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "../src/rrr/RRRSequence.h"

TEST_CASE("RRRSequence test 1", "Manual constructor")
{
    RRRSequence seq = RRRSequence("10110110", 3, 2, RRRTable(2));

    REQUIRE(seq.select1(1) == 0);
    REQUIRE(seq.select1(2) == 2);
    REQUIRE(seq.select1(3) == 3);
    REQUIRE(seq.select1(4) == 5);
    REQUIRE(seq.select1(5) == 6);

    REQUIRE(seq.select0(1) == 1);
    REQUIRE(seq.select0(2) == 4);
    REQUIRE(seq.select0(3) == 7);

    REQUIRE(seq.rank1(0) == 1);
    REQUIRE(seq.rank1(1) == 1);
    REQUIRE(seq.rank1(2) == 2);
    REQUIRE(seq.rank1(3) == 3);
    REQUIRE(seq.rank1(4) == 3);
    REQUIRE(seq.rank1(5) == 4);
    REQUIRE(seq.rank1(6) == 5);
    REQUIRE(seq.rank1(7) == 5);

    REQUIRE(seq.rank0(0) == 0);
    REQUIRE(seq.rank0(1) == 1);
    REQUIRE(seq.rank0(2) == 1);
    REQUIRE(seq.rank0(3) == 1);
    REQUIRE(seq.rank0(4) == 2);
    REQUIRE(seq.rank0(5) == 2);
    REQUIRE(seq.rank0(6) == 2);
    REQUIRE(seq.rank0(7) == 3);
}
