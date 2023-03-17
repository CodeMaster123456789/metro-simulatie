#include <iostream>
#include "Metro.h"
#include "TicTacToeExporter.h"

using namespace std;

int main(int argc, char **argv) {
	Metro ttt;
	TicTacToeHTMLTablesIconExporter exporter;
	
	exporter.documentStart(cout);

	exporter.documentEnd(cout);
}
