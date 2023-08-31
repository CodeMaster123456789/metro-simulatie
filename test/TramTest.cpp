#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "gtest/gtest.h"

using namespace std;

#include "../src/Tram.h"

class TramTest: public ::testing::Test {
protected:
    TramTest() {}

    friend class Tram;
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    Tram t;
};

/**
Tests the constructor.
*/
TEST_F(TramTest,ConstructorTest) {
    t = Tram(1);
    EXPECT_TRUE(t.getLijnNr() == 1);
    EXPECT_TRUE(t.getHuidigeStation() == NULL);
    EXPECT_TRUE(t.getBeginstation() == NULL);

    EXPECT_DEATH(Tram(-1), "LijnNr moet een positieve getal zijn");

}

TEST_F(TramTest,TramConstructor) {
    EXPECT_TRUE(t.getLijnNr() == -1);
    EXPECT_TRUE(t.getBeginstation() == NULL);
    EXPECT_TRUE(t.getHuidigeStation() == NULL);
}

//
// Created by tigok on 4/05/2023.
//
