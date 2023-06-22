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

    REQUIRE(s,"een variable voor een station");

    this->stationen.push_back(s);

    ENSURE(s == new Station,"s is een nieuw station en wordt toegevoegd");
}

void Metro::addTram(Tram *t) {                                  // het zal de argument voor de element Station toevoegen.

    REQUIRE(t,"dit is een variable voor een nieuwe tram");

    this->trammen.push_back(t);

    ENSURE(t == new Tram,"t is een nieuwe tram die is toegevoed in de tram lijst");

}

Station *Metro::findStation(string naam) {                      // het zoekt naar de element zijn argument

    REQUIRE(naam == "","deze naam wordt gebruikt om mee te zoeken");

    for (size_t i = 0; i < stationen.size();i++) {              // bijvoorbeeld het argument van het element was A
        Station * s = stationen [i];                            // bij de nieuwe benaming gaan die naar het laaste bekeken argument bekijken
        if (s->getNaam() == naam) {                             // zodat die ermee rekening houd dat de volgende argument moet zijn
            return s;
        }
    }
    return NULL;

    ENSURE(naam == ""," "" staat voor de naam van de station die we willen vinden en indien het s is bestaat die station");

}

const vector<Station *> & Metro::getStationen() {               // geeft de Station weer.
    return this->stationen;

    ENSURE(getStationen() == stationen,"het geeft jouw de lijst met al de beschikbare stations");

}

const vector<Tram *> & Metro::getTrammen() {                    // geeft de Tram weer.
    return this->trammen;

    ENSURE(getTrammen() == trammen,"het geeft jouw een lijst weer met al de beschikbare trammen");

}

void Metro::moveTrams() {
    for (size_t i = 0; i < trammen.size();i++) {
        Tram * huidigetram = trammen[i];
        huidigetram->move();
    }
}

int Metro::getTijd() {
    return tijdstip;

    ENSURE(getTijd() == tijdstip,"het geeft jouw de tijdstip weer");

}

void Metro::simulate(int eindtijd) {

    REQUIRE(eindtijd >= 0,"moet geen negatief getal zijn");

    while (tijdstip < eindtijd) {
        cout << "=== " << getTijd() << " ===" << endl;
        moveTrams();
        tijdstip++;
        cout << endl;
    }

    ENSURE(eindtijd == tijdstip, "door de gegeven eindtijd houd de simulatie rekening mee hoeveel stappen er worden genomen");

}
