#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "gtest/gtest.h"

using namespace std;

#include "../src/Metro.h"
#include "../src/MetroUtils.h"
#include "../src/MetroExporter.h"

class MetroOutputTest: public ::testing::Test {
protected:
	friend class Metro;

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}

	Metro sim_;

};


// Tests the compare files
TEST_F(MetroOutputTest, FileCompare) {
    ASSERT_TRUE(DirectoryExists("testOutput"));
}