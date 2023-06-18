#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

//#include "src/Metro.h"
//#include "test/MetroDomainTests.cpp"
//#include "test/MetroOutputTests.cpp"
//#include "test/MetroInputTests.cpp"
//#include "test/TramTest.cpp"


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_death_test_style="threadsafe";
	return RUN_ALL_TESTS();
}
