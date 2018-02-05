#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "basics.h"

TEST_CASE( "Test 'findSecondFreeSpace'", "[findSecondFreeSpace]" ) {
	REQUIRE( findSecondFreeSpace(0,0) == 0 );
    REQUIRE( findSecondFreeSpace(1,0) == 2 );
    REQUIRE( findSecondFreeSpace(2,0) == 5 );
    REQUIRE( findSecondFreeSpace(3,0) == 7 );
    REQUIRE( findSecondFreeSpace(0,5) == 5 );
    REQUIRE( findSecondFreeSpace(1,5) == 7 );
    REQUIRE( findSecondFreeSpace(2,5) == 10 );
    REQUIRE( findSecondFreeSpace(3,5) == 12 );
}

TEST_CASE( "Test 'findFirstFreeSpace'", "[findFirstFreeSpace]" ) {
	REQUIRE( findFirstFreeSpace(0,0) == 0 );
	REQUIRE( findFirstFreeSpace(1,0) == 2 );
	REQUIRE( findFirstFreeSpace(2,0) == 3 );
	REQUIRE( findFirstFreeSpace(3,0) == 5 );
	REQUIRE( findFirstFreeSpace(0,5) == 5 );
	REQUIRE( findFirstFreeSpace(1,5) == 7 );
	REQUIRE( findFirstFreeSpace(2,5) == 8 );
	REQUIRE( findFirstFreeSpace(3,5) == 10 );
}

TEST_CASE( "Test 'findPairsByStep'", "[findPairsByStep]" ) {
	REQUIRE( findPairsByStep(1,1,0,0) == 0 );
	REQUIRE( findPairsByStep(1,1,0,1) == 1 );
	REQUIRE( findPairsByStep(1,3,0,0) == 1 );
	REQUIRE( findPairsByStep(1,3,0,1) == 2 );
	REQUIRE( findPairsByStep(2,3,0,0) == 4 );
	REQUIRE( findPairsByStep(2,3,0,1) == 6 );
	REQUIRE( findPairsByStep(3,3,0,0) == 0 );
	REQUIRE( findPairsByStep(3,3,0,1) == 3 );
	REQUIRE( findPairsByStep(1,1,5,0) == 5 );
	REQUIRE( findPairsByStep(1,1,5,1) == 6 );
	REQUIRE( findPairsByStep(1,3,5,0) == 6 );
	REQUIRE( findPairsByStep(1,3,5,1) == 7 );
	REQUIRE( findPairsByStep(2,3,5,0) == 9 );
	REQUIRE( findPairsByStep(2,3,5,1) == 11 );
	REQUIRE( findPairsByStep(3,3,5,0) == 5 );
	REQUIRE( findPairsByStep(3,3,5,1) == 8 );
}
