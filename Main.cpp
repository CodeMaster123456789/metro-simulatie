#include <iostream>
#include "src/Metro.h"
#include "src/MetroImporter.h"

using namespace std;

int main(int argc, char **argv) {
	Metro simulatie;
    MetroImporter importer;
    importer.importMetro("testInput/test.xml",cerr,simulatie);
}