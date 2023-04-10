#include <iostream>
#include "src/Metro.h"
#include "src/MetroImporter.h"
#include "src/MetroExporter.h"
#include <string>
using namespace std;

int main(int argc, char **argv) {
	Metro simulatie;
    MetroImporter importer;
    importer.importMetro("testInput/test.xml",cerr,simulatie);
    MetroExporter exporter;
    exporter.simpleUitvoer("output/test.txt",simulatie);
}

// hier zorgen we ervoor dat we de gevraagde documenten in een XML-file kunnen laten lezen door het programma.