#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "gtest/gtest.h"

using namespace std;

#include "../src/Tram.h"

class TramTest: public ::testing::Test {
protected:
    friend class Tram;
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    Tram t;

};

/**
Tests the constructor.
*/
TEST_F(TramTest, ConstructorTest) {
    t = Tram(1,-1,1);
    EXPECT_TRUE(t.getLijnNr() == 1);
    EXPECT_TRUE(t.getHuidigeStation() == nullptr);
    EXPECT_TRUE(t.getBeginstation() == nullptr);

    EXPECT_DEATH(Tram(-1,-1,0),"LijnNr moet een positieve getal zijn");
    EXPECT_DEATH(Tram(1,0,0),"aantaldefecten mag niet 0 zijn");
    EXPECT_DEATH(Tram(1,-1,-1),"reparatietijd mag niet negatief zijn");
}


//
// Created by tigok on 4/05/2023.
//
