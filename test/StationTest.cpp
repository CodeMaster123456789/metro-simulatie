#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "gtest/gtest.h"

using namespace std;

#include "../src/Station.h"

class StationTest: public ::testing::Test {
protected:
    StationTest() {}

    friend class Station;

    Station s;
};

TEST_F(StationTest, ConstructorTest) {
    s = Station("Beveren",12);

    EXPECT_TRUE(s.getNaam() == "Beveren");
    EXPECT_TRUE(s.getSpoorNr() == 12);
    EXPECT_TRUE(s.getVolgende() == NULL);
    EXPECT_TRUE(s.getVorige() == NULL);

    EXPECT_DEATH(Station("Antwerpen",12),"de naam van de Station is fout");
    EXPECT_DEATH(Station("Beveren",10),"de spoorNr van de Station is fout");

};




//
// Created by Oksuz on 31/08/2023.
//
