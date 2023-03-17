#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "gtest/gtest.h"

using namespace std;

#include "../src/Metro.h"

class MetroDomainTest: public ::testing::Test {
protected:
	friend class Metro;
	// You should make the members protected s.t. they can be
	// accessed from sub-classes.

	Metro sim_;

};

/**
Tests the default constructor.
*/
TEST_F(MetroDomainTest, DefaultConstructor) {
	EXPECT_TRUE(sim_.properlyInitialized());
}