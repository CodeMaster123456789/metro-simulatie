#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "gtest/gtest.h"

using namespace std;

#include "../src/Metro.h"
#include "../src/MetroUtils.h"
#include "../src/MetroImporter.h"

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

	ofstream myfile;
	//SuccessEnum importResult;

}