#include "../headers/catch.h"
#include "../headers/basics.h"
#include "../headers/Matrix.h"
#include "../headers/findPartitions.h"

TEST_CASE( "findPartitions", "[findPartitionsTests]" )
{
	Matrix* mat = new Matrix(2,5);

	findPartitions(5, 7, 8, mat, 0, 0);

	REQUIRE( mat->getEntry(0,0) == 4 );
	REQUIRE( mat->getEntry(0,1) == 3 );
	REQUIRE( mat->getEntry(0,2) == 0 );
	REQUIRE( mat->getEntry(0,3) == 0 );
	REQUIRE( mat->getEntry(0,4) == 0 );
	REQUIRE( mat->getEntry(1,0) == 5 );
	REQUIRE( mat->getEntry(1,1) == 2 );
	REQUIRE( mat->getEntry(1,2) == 1 );
	REQUIRE( mat->getEntry(1,3) == 0 );
	REQUIRE( mat->getEntry(1,4) == 0 );

	delete mat;

	mat = new Matrix(6,14);

	findPartitions(14, 15, 20, mat, 0, 0);

	REQUIRE( mat->getEntry(0,0) == 11 );
	REQUIRE( mat->getEntry(0,1) == 4 );
	REQUIRE( mat->getEntry(0,2) == 0 );
	REQUIRE( mat->getEntry(0,3) == 0 );
	REQUIRE( mat->getEntry(0,4) == 0 );
	REQUIRE( mat->getEntry(0,5) == 0 );
	REQUIRE( mat->getEntry(0,6) == 0 );
	REQUIRE( mat->getEntry(0,7) == 0 );
	REQUIRE( mat->getEntry(0,8) == 0 );
	REQUIRE( mat->getEntry(0,9) == 0 );
	REQUIRE( mat->getEntry(0,10) == 0 );
	REQUIRE( mat->getEntry(0,11) == 0 );
	REQUIRE( mat->getEntry(0,12) == 0 );
	REQUIRE( mat->getEntry(0,13) == 0 );

	REQUIRE( mat->getEntry(1,0) == 9 );
	REQUIRE( mat->getEntry(1,1) == 7 );
	REQUIRE( mat->getEntry(1,2) == 0 );
	REQUIRE( mat->getEntry(1,3) == 0 );
	REQUIRE( mat->getEntry(1,4) == 0 );
	REQUIRE( mat->getEntry(1,5) == 0 );
	REQUIRE( mat->getEntry(1,6) == 0 );
	REQUIRE( mat->getEntry(1,7) == 0 );
	REQUIRE( mat->getEntry(1,8) == 0 );
	REQUIRE( mat->getEntry(1,9) == 0 );
	REQUIRE( mat->getEntry(1,10) == 0 );
	REQUIRE( mat->getEntry(1,11) == 0 );
	REQUIRE( mat->getEntry(1,12) == 0 );
	REQUIRE( mat->getEntry(1,13) == 0 );

	REQUIRE( mat->getEntry(2,0) == 12 );
	REQUIRE( mat->getEntry(2,1) == 5 );
	REQUIRE( mat->getEntry(2,2) == 0 );
	REQUIRE( mat->getEntry(2,3) == 0 );
	REQUIRE( mat->getEntry(2,4) == 0 );
	REQUIRE( mat->getEntry(2,5) == 0 );
	REQUIRE( mat->getEntry(2,6) == 0 );
	REQUIRE( mat->getEntry(2,7) == 0 );
	REQUIRE( mat->getEntry(2,8) == 0 );
	REQUIRE( mat->getEntry(2,9) == 0 );
	REQUIRE( mat->getEntry(2,10) == 0 );
	REQUIRE( mat->getEntry(2,11) == 0 );
	REQUIRE( mat->getEntry(2,12) == 0 );
	REQUIRE( mat->getEntry(2,13) == 0 );

	REQUIRE( mat->getEntry(3,0) == 10 );
	REQUIRE( mat->getEntry(3,1) == 8 );
	REQUIRE( mat->getEntry(3,2) == 0 );
	REQUIRE( mat->getEntry(3,3) == 0 );
	REQUIRE( mat->getEntry(3,4) == 0 );
	REQUIRE( mat->getEntry(3,5) == 0 );
	REQUIRE( mat->getEntry(3,6) == 0 );
	REQUIRE( mat->getEntry(3,7) == 0 );
	REQUIRE( mat->getEntry(3,8) == 0 );
	REQUIRE( mat->getEntry(3,9) == 0 );
	REQUIRE( mat->getEntry(3,10) == 0 );
	REQUIRE( mat->getEntry(3,11) == 0 );
	REQUIRE( mat->getEntry(3,12) == 0 );
	REQUIRE( mat->getEntry(3,13) == 0 );

	REQUIRE( mat->getEntry(4,0) == 13 );
	REQUIRE( mat->getEntry(4,1) == 6 );
	REQUIRE( mat->getEntry(4,2) == 0 );
	REQUIRE( mat->getEntry(4,3) == 0 );
	REQUIRE( mat->getEntry(4,4) == 0 );
	REQUIRE( mat->getEntry(4,5) == 0 );
	REQUIRE( mat->getEntry(4,6) == 0 );
	REQUIRE( mat->getEntry(4,7) == 0 );
	REQUIRE( mat->getEntry(4,8) == 0 );
	REQUIRE( mat->getEntry(4,9) == 0 );
	REQUIRE( mat->getEntry(4,10) == 0 );
	REQUIRE( mat->getEntry(4,11) == 0 );
	REQUIRE( mat->getEntry(4,12) == 0 );
	REQUIRE( mat->getEntry(4,13) == 0 );

	REQUIRE( mat->getEntry(5,0) == 14 );
	REQUIRE( mat->getEntry(5,1) == 3 );
	REQUIRE( mat->getEntry(5,2) == 2 );
	REQUIRE( mat->getEntry(5,3) == 1 );
	REQUIRE( mat->getEntry(5,4) == 0 );
	REQUIRE( mat->getEntry(5,5) == 0 );
	REQUIRE( mat->getEntry(5,6) == 0 );
	REQUIRE( mat->getEntry(5,7) == 0 );
	REQUIRE( mat->getEntry(5,8) == 0 );
	REQUIRE( mat->getEntry(5,9) == 0 );
	REQUIRE( mat->getEntry(5,10) == 0 );
	REQUIRE( mat->getEntry(5,11) == 0 );
	REQUIRE( mat->getEntry(5,12) == 0 );
	REQUIRE( mat->getEntry(5,13) == 0 );

	delete mat;
}
