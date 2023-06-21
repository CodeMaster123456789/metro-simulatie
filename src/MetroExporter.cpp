#include <fstream>
#include "../lib/DesignByContract.h"
#include "MetroExporter.h"
#include "MetroUtils.h"

using namespace std;


MetroExporter::MetroExporter() {
	_initCheck = this;
    ENSURE(properlyInitialized(),
			"constructor must end in properlyInitialized state");
}


bool MetroExporter::properlyInitialized() {
	return _initCheck == this;
}

void MetroExporter::simpleUitvoer(const char *pad, Metro &simulatie) {                   // dit geld voor de gedeelte van Station.
    ofstream MyFile(pad);                                                        // hier zegen we hoe de programma gelijk als op aade XLM file moet lezen.

    REQUIRE(FileExists(pad), "moet een geldige pad zijn");

    MyFile << "--== STATIONS ==--" << endl;
    for (size_t i = 0; i < simulatie.getStationen().size();i++) {                   // we zeggen eerst wat de child element.
        Station *s = simulatie.getStationen()[i];                                   // dan voegen we erna zijn argument aan toe.
        MyFile << "= Station " << s->getNaam() << " = " << endl;                               // en zo voor elke regel die in de XLM file geschreven staat.
        MyFile << "* Spoor " << s->getSpoorNr() << ":"<< endl;
        MyFile << "     <- Station " << s->getVorige()->getNaam() << endl;
        MyFile << "     -> Station " << s->getVolgende()->getNaam() << endl;
        MyFile << endl;
    }                                                                               // dit geldt voor het gedeelte van Tram
    MyFile << endl;
    MyFile << "--== TRAMS ==--" << endl;
    for (size_t i = 0; i < simulatie.getTrammen().size();i++) {
        Tram * t = simulatie.getTrammen()[i];
        MyFile << "Tram " << t->getLijnNr() << endl;
        MyFile << "     type: " << t->getType() << endl;
        MyFile << "     snelheid: " << t->getSnelheid() << endl;
        MyFile << "     huidigestation: " << t->getHuidigeStation()->getNaam() << endl;
        MyFile << endl;
    }

    MyFile.close();
}

void MetroExporter::tramMoved(Tram *t, Station *s) {
    cout << "Tram " << t->getLijnNr() << " reed van Station " << t->getHuidigeStation()->getNaam() << " naar Station " << s->getNaam() << endl;
}
