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

TEST_CASE("RRRSequence test 2", "Auto constructor")
{
    auto seq_auto = RRRSequence("10110110", RRRTable(2));

    REQUIRE(seq_auto.select1(1) == 0);
    REQUIRE(seq_auto.select1(2) == 2);
    REQUIRE(seq_auto.select1(3) == 3);
    REQUIRE(seq_auto.select1(4) == 5);
    REQUIRE(seq_auto.select1(5) == 6);

    REQUIRE(seq_auto.select0(1) == 1);
    REQUIRE(seq_auto.select0(2) == 4);
    REQUIRE(seq_auto.select0(3) == 7);

    REQUIRE(seq_auto.rank1(0) == 1);
    REQUIRE(seq_auto.rank1(1) == 1);
    REQUIRE(seq_auto.rank1(2) == 2);
    REQUIRE(seq_auto.rank1(3) == 3);
    REQUIRE(seq_auto.rank1(4) == 3);
    REQUIRE(seq_auto.rank1(5) == 4);
    REQUIRE(seq_auto.rank1(6) == 5);
    REQUIRE(seq_auto.rank1(7) == 5);

    REQUIRE(seq_auto.rank0(0) == 0);
    REQUIRE(seq_auto.rank0(1) == 1);
    REQUIRE(seq_auto.rank0(2) == 1);
    REQUIRE(seq_auto.rank0(3) == 1);
    REQUIRE(seq_auto.rank0(4) == 2);
    REQUIRE(seq_auto.rank0(5) == 2);
    REQUIRE(seq_auto.rank0(6) == 2);
    REQUIRE(seq_auto.rank0(7) == 3);
}

TEST_CASE("RRRSequence test 3", "Compare two constructors")
{
    auto seq_auto = RRRSequence("10110110", RRRTable(2));
    auto seq_manual = RRRSequence("10110110", 3, 2, RRRTable(2));

    REQUIRE(seq_auto.select1(1) == seq_manual.select1(1));
    REQUIRE(seq_auto.select1(2) == seq_manual.select1(2));
    REQUIRE(seq_auto.select1(3) == seq_manual.select1(3));
    REQUIRE(seq_auto.select1(4) == seq_manual.select1(4));
    REQUIRE(seq_auto.select1(5) == seq_manual.select1(5));

    REQUIRE(seq_auto.select0(1) == seq_auto.select0(1));
    REQUIRE(seq_auto.select0(2) == seq_auto.select0(2));
    REQUIRE(seq_auto.select0(3) == seq_auto.select0(3));

    REQUIRE(seq_auto.rank1(0) == seq_auto.rank1(0));
    REQUIRE(seq_auto.rank1(1) == seq_auto.rank1(1));
    REQUIRE(seq_auto.rank1(2) == seq_auto.rank1(2));
    REQUIRE(seq_auto.rank1(3) == seq_auto.rank1(3));
    REQUIRE(seq_auto.rank1(4) == seq_auto.rank1(4));
    REQUIRE(seq_auto.rank1(5) == seq_auto.rank1(5));
    REQUIRE(seq_auto.rank1(6) == seq_auto.rank1(6));
    REQUIRE(seq_auto.rank1(7) == seq_auto.rank1(7));

    REQUIRE(seq_auto.rank0(0) == seq_auto.rank0(0));
    REQUIRE(seq_auto.rank0(1) == seq_auto.rank0(1));
    REQUIRE(seq_auto.rank0(2) == seq_auto.rank0(2));
    REQUIRE(seq_auto.rank0(3) == seq_auto.rank0(3));
    REQUIRE(seq_auto.rank0(4) == seq_auto.rank0(4));
    REQUIRE(seq_auto.rank0(5) == seq_auto.rank0(5));
    REQUIRE(seq_auto.rank0(6) == seq_auto.rank0(6));
    REQUIRE(seq_auto.rank0(7) == seq_auto.rank0(7));
}
