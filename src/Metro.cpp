#include "Metro.h"
#include "../lib/DesignByContract.h"
//-----------------------------------------
///   Metro
//-----------------------------------------

Metro::Metro() {
	_initCheck = this;
	reset();
	ENSURE(properlyInitialized(),
			"constructor must end in properlyInitialized state");
}

void Metro::reset() {
	REQUIRE(this->properlyInitialized(), "Metro wasn't initialized when calling setMoves");

    tijdstip = 0;

    for (size_t i = 0; i < trammen.size();i++) {
        Tram * huidigetram = trammen[i];
        huidigetram->reset();
    }

	ENSURE(properlyInitialized(),
			"constructor must end in properlyInitialized state");
}


bool Metro::properlyInitialized() {
	return _initCheck == this;
}

void Metro::addStation(Station *s) {                            // het zal de argument voor de element Station toevoegen.
    this->stationen.push_back(s);
}

void Metro::addTram(Tram *t) {                                  // het zal de argument voor de element Station toevoegen.
    this->trammen.push_back(t);
}

Station *Metro::findStation(string naam) {                      // het zoekt naar de element zijn argument
    for (size_t i = 0; i < stationen.size();i++) {              // bijvoorbeeld het argument van het element was A
        Station * s = stationen [i];                            // bij de nieuwe benaming gaan die naar het laaste bekeken argument bekijken
        if (s->getNaam() == naam) {                             // zodat die ermee rekening houd dat de volgende argument moet zijn
            return s;
        }
    }
    return nullptr;
}

const vector<Station *> & Metro::getStationen() {               // geeft de Station weer.
    return this->stationen;
}

const vector<Tram *> & Metro::getTrammen() {                    // geeft de Tram weer.
    return this->trammen;
}

void Metro::moveTrams() {
    for (size_t i = 0; i < trammen.size();i++) {
        Tram * huidigetram = trammen[i];
        huidigetram->move();
    }
}

int Metro::getTijd() {
    return tijdstip;
}

void Metro::simulate(int eindtijd) {
    while (tijdstip < eindtijd) {
        cout << "=== " << getTijd() << " ===" << endl;
        moveTrams();
        tijdstip++;
        cout << endl;
    }
}
