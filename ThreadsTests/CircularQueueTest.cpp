// CircularQueueTest.cpp

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "..\Threads\CircularQueue.h"

TEST_CASE( "Test Add", "[single-file]" ) 
{
    CircularQueue cq;
    
    cq.add("1");
    REQUIRE( cq.getRawQueue() == "1" );
    
    cq.add("2");
    cq.add("3");
    cq.add("4");
    cq.add("5");
    REQUIRE( cq.getRawQueue() == "12345" );
    
    cq.add("6");
    REQUIRE( cq.getRawQueue() == "62345" );
    cq.add("7");
    REQUIRE( cq.getRawQueue() == "67345" );
    cq.add("8");
    REQUIRE( cq.getRawQueue() == "67845" );
    cq.add("9");
    REQUIRE( cq.getRawQueue() == "67895" );
    cq.add("a");
    REQUIRE( cq.getRawQueue() == "6789a" );
    cq.add("b");
    REQUIRE( cq.getRawQueue() == "b789a" );
}

TEST_CASE( "Test Remove", "[single-file]" ) 
{
    CircularQueue cq;
    
    REQUIRE( cq.remove() == "" );
    
    cq.add("1");
    REQUIRE( cq.remove() == "1" );
    REQUIRE( cq.isEmpty() == true );

    cq.add("1");
    cq.add("2");
    REQUIRE( cq.remove() == "1" );
    REQUIRE( cq.isEmpty() == false );
    REQUIRE( cq.remove() == "2" );
    REQUIRE( cq.isEmpty() == true );
    
    cq.add("1");
    cq.add("2");
    cq.add("3");
    cq.add("4");
    cq.add("5");
    cq.add("6");
    REQUIRE( cq.remove() == "2" );
}

TEST_CASE( "Test Full & Empty", "[single-file]" ) 
{
    CircularQueue cq;
    
    REQUIRE( cq.isEmpty() == true );
    REQUIRE( cq.isFull() == false );
    
    cq.add("banana");
    
    REQUIRE( cq.isEmpty() == false);
    REQUIRE( cq.isFull() == false);
    
    cq.add("apple");
    cq.add("apple");
    cq.add("banana");
    cq.add("orange");
    
    REQUIRE( cq.isEmpty() == false);
    REQUIRE( cq.isFull() == true);

}


// Compile & run:
// - g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success
// - cl -EHsc -I%CATCH_SINGLE_INCLUDE% 010-TestCase.cpp && 010-TestCase --success

