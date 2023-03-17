#include <iostream>
#include "Metro.h"
#include "MetroImporter.h"

using namespace std;

int main(int argc, char **argv) {
	Metro simulatie;
    MetroImporter importer;
    importer.importMetro("testInput/test.xml",cerr,simulatie);
}