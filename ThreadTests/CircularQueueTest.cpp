// CircularQueueTest.cpp

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "..\Threads\CircularQueue.h"

TEST_CASE( "Circular Queue", "[single-file]" ) {
    CircularQueue q;
    
    REQUIRE( q.isEmpty() == true );
    REQUIRE( q.isFull() == false );
}


// Compile & run:
// - g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success
// - cl -EHsc -I%CATCH_SINGLE_INCLUDE% 010-TestCase.cpp && 010-TestCase --success

