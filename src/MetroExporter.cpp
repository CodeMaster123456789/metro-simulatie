#include <fstream>
#include "../lib/DesignByContract.h"
#include "MetroExporter.h"

using namespace std;


MetroExporter::MetroExporter() {
	_initCheck = this;
    ENSURE(properlyInitialized(),
			"constructor must end in properlyInitialized state");
}


bool MetroExporter::properlyInitialized() {
	return _initCheck == this;
}

void MetroExporter::simpleUitvoer(string pad, Metro &simulatie) {                   // dit geld voor de gedeelte van Station.
    ofstream MyFile(pad);                                                        // hier zegen we hoe de programma gelijk als op aade XLM file moet lezen.
    for (size_t i = 0; i < simulatie.getStationen().size();i++) {                   // we zeggen eerst wat de child element.
        Station *s = simulatie.getStationen()[i];                                   // dan voegen we erna zijn argument aan toe.
        MyFile << "Station " << s->getNaam() << endl;                               // en zo voor elke regel die in de XLM file geschreven staat.
        MyFile << "<- Station " << s->getVorige()->getNaam() << endl;
        MyFile << "-> Station " << s->getVolgende()->getNaam() << endl;
        MyFile << "Spoor " << s->getSpoorNr() << endl << endl;


    }                                                                               // dit geldt voor het gedeelte van Tram.
    for (size_t i = 0; i < simulatie.getTrammen().size();i++) {
        Tram * t = simulatie.getTrammen()[i];
        MyFile << "Tram " << t->getLijnNr() << " in Station " << t->getHuidigeStation()->getNaam() << endl << endl;
    }

    MyFile.close();
}
