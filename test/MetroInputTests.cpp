#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "gtest/gtest.h"

using namespace std;

#include "../src/Metro.h"
#include "../src/MetroUtils.h"
#include "../src/MetroImporter.h"
#include "../src/MetroExporter.h"

class MetroInputTest: public ::testing::Test {
protected:
	friend class Metro;

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}

	Metro sim_;
};

/**
Tests InputHappyDay
*/
TEST_F(MetroInputTest, InputHappyDay) {
	ASSERT_TRUE(DirectoryExists("testInput"));

    Metro metro;
    MetroImporter importer;
    EXPECT_TRUE(importer.importMetro("testInput/test.xml",cerr,metro)== Success);


}

TEST_F(MetroInputTest, importtest){
    Metro metro;
    MetroImporter importer;
    EXPECT_DEATH(importer.importMetro("k",cerr,metro),"00");

    EXPECT_DEATH(importer.importMetro("testInput/test01.xml",cerr,metro),"01");

    EXPECT_DEATH(importer.importMetro("testInput/test02.xml",cerr,metro),"02");
}