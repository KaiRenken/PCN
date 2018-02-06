#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "basics.h"
#include "Matrix.h"
#include "findPartitions.h"

// Test methods in 'basics.h'
TEST_CASE( "findPairsByStep", "[basicsTests]" ) {
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

TEST_CASE( "findFirstFreeSpace", "[basicsTest]" ) {
	REQUIRE( findFirstFreeSpace(0,0) == 0 );
	REQUIRE( findFirstFreeSpace(1,0) == 2 );
	REQUIRE( findFirstFreeSpace(2,0) == 3 );
	REQUIRE( findFirstFreeSpace(3,0) == 5 );
	REQUIRE( findFirstFreeSpace(0,5) == 5 );
	REQUIRE( findFirstFreeSpace(1,5) == 7 );
	REQUIRE( findFirstFreeSpace(2,5) == 8 );
	REQUIRE( findFirstFreeSpace(3,5) == 10 );
}

TEST_CASE( "findSecondFreeSpace", "[basicsTests]" ) {
	REQUIRE( findSecondFreeSpace(0,0) == 0 );
    REQUIRE( findSecondFreeSpace(1,0) == 2 );
    REQUIRE( findSecondFreeSpace(2,0) == 5 );
    REQUIRE( findSecondFreeSpace(3,0) == 7 );
    REQUIRE( findSecondFreeSpace(0,5) == 5 );
    REQUIRE( findSecondFreeSpace(1,5) == 7 );
    REQUIRE( findSecondFreeSpace(2,5) == 10 );
    REQUIRE( findSecondFreeSpace(3,5) == 12 );
}

// Test methods in 'Matrix.h'
TEST_CASE( "getEntry", "[MatrixTests]" ) {
	
	Matrix* mat = new Matrix(10,20);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			mat->setEntry(i, j, i + j);
		}
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			REQUIRE( mat->getEntry(i,j) == i + j );
		}
	}
	
	delete mat;
}

TEST_CASE( "getLines", "[MatrixTests]" ) {
	
	Matrix* mat = new Matrix(10,20);
	
	REQUIRE( mat->getLines() == 10 );
	
	delete mat;
}

TEST_CASE( "getColumns", "[MatrixTests]" ) {
	
	Matrix* mat = new Matrix(10,20);
	
	REQUIRE( mat->getColumns() == 20 );
	
	delete mat;
}

// Test 'findPartitions'
TEST_CASE( "findPartitions", "[findPartitionsTests]" ) {
	
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
