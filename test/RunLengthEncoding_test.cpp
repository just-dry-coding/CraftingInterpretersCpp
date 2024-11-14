#include <catch2/catch_all.hpp>
import RunLengthEncoding;

TEST_CASE("RunLengthEncoding Basic Operations", "[RunLengthEncoding]") {
    RunLengthEncoding<int> rle;

    SECTION("Adding a single element") {
        rle.add(10);
        REQUIRE(rle.get(0) == 10);
    }

    SECTION("Adding consecutive identical elements increments upperOriginIndex") {
        rle.add(10);
        rle.add(10);
        rle.add(10);

        REQUIRE(rle.get(0) == 10);
        REQUIRE(rle.get(1) == 10);
        REQUIRE(rle.get(2) == 10);
    }

    SECTION("Adding a new unique element creates a new entry") {
        rle.add(10);
        rle.add(10);
        rle.add(20);

        REQUIRE(rle.get(0) == 10);
        REQUIRE(rle.get(1) == 10);
        REQUIRE(rle.get(2) == 20);
    }

    SECTION("Retrieving values by upperOriginIndex") {
        rle.add(5);
        rle.add(5);
        rle.add(5);
        rle.add(10);
        rle.add(10);
        rle.add(20);

        REQUIRE(rle.get(0) == 5);
        REQUIRE(rle.get(1) == 5);
        REQUIRE(rle.get(2) == 5);
        REQUIRE(rle.get(3) == 10);
        REQUIRE(rle.get(4) == 10);
        REQUIRE(rle.get(5) == 20);
    }

    SECTION("Adding mixed values maintains the correct sequence") {
        rle.add(1);
        rle.add(1);
        rle.add(2);
        rle.add(3);
        rle.add(3);
        rle.add(3);

        REQUIRE(rle.get(0) == 1);
        REQUIRE(rle.get(1) == 1);
        REQUIRE(rle.get(2) == 2);
        REQUIRE(rle.get(3) == 3);
        REQUIRE(rle.get(4) == 3);
        REQUIRE(rle.get(5) == 3);
    }
}
