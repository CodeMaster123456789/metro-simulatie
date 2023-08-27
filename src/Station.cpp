//
// Created by tigok on 17/03/2023.
//

#include "Station.h"
#include "Metro.h"
#include "../lib/DesignByContract.h"

Metro * Station::sim = NULL;

Station::Station() {                                                    // deze gegevens zet ik als mijn defaults.

    this->naam = "";
    this->spoorNr = -1;
    this->volgende = NULL;
    this->vorige = NULL;

    ENSURE(getNaam() == "", "dit wordt de naam van de Station");
    ENSURE(getSpoorNr() == spoorNr, "dit is een standaard waarde");
    ENSURE(getVolgende() == NULL, "de volgende zal door middel van de gegeven de tram de volgende halte weergeven");
    ENSURE(getVorige() == NULL, "de vorige zal door middel van de gegeven tram de vorige weergeven");

}

Station::Station(string naam, int spoorNr) {                            // hier geeft ik de gegevens een beginwaarde weer.

    REQUIRE(spoorNr >= 0, "de nummer van de spoor");
    REQUIRE(this->naam == "","een naam voor de station zelf");

    this->naam = naam;
    this->spoorNr = spoorNr;
    this->volgende = NULL;
    this->vorige = NULL;

    ENSURE(getNaam() == naam, "dit is de naam van de tram");
    ENSURE(getSpoorNr() == spoorNr, "dit is de nummer van de spoor");
    ENSURE(getVolgende() == NULL, "dit geeft de volgende halte weer");
    ENSURE(getVorige() == NULL, "dit geeft de vorige halte weer");

}

void Station::setSpoorNr(int spoor) {                                   // hier noem ik spoor als het argument voor spoorNr.

    REQUIRE(getSpoorNr() >= 0, "het getal moet niet negatief zijn");

    this->spoorNr = spoor;

    ENSURE(getSpoorNr() == spoor, "het geeft jou de nummer van de spoor weer");


}

int Station::getSpoorNr() {                                             // Als ik dit oproep geeft het mij het nodige getal voor spoorNr.
    return this->spoorNr;

    ENSURE(getSpoorNr() == spoorNr, "het geeft jouw de spoornummer weer");

}

void Station::setNaam(string name) {                                    // hier zeg ik dat name mijn argument is voor naam.

    REQUIRE(getNaam() == "", "een naam voor de Station");

    this->naam = name;

    ENSURE(getNaam() == naam, "dit geeft jouw de naam weer van de Station");

}

string Station::getNaam() {                                             // Als ik dit oproep geeft het mij de text voor naam weer.
    return this->naam;

    ENSURE(getNaam() == naam, "dit geeft jouw de naam weer van de tram");

}

void Station::setVolgende(Station *next) {
    REQUIRE(next, "de next is de volgende station van de gegeven huidige station");

    this->volgende = next;

    ENSURE(getVolgende() == next, "dit geeft jouw de Station die de tram nog moet paseren");

}

Station *Station::getVolgende() {                                       // Als ik dit oproep geeft het mij de text voor volgende weer.
    return this->volgende;

    ENSURE(getVolgende() == volgende, "dit geeft jouw de volgende halte weer");

}

void Station::setVorige(Station *previous) {
    REQUIRE(previous,"dit geeft de vorige station weer");

    this->vorige = previous;

    ENSURE(getVorige() == previous, "dit geeft u de gepaseerde station weer");
}

Station *Station::getVorige() {                                         // Als ik dit oproep geeft het mij de text voor vorige weer.
    return this->vorige;

    ENSURE(getVorige() == vorige,"de vorige geeft jouw de bezochte station weer");

}

string Station::getType() {
    return this->type;

    ENSURE(getType() == type, "het geeft jouw de type van de tram");
}

Tram *Station::getHuidigeTram() {
    vector<Tram *> trams = sim->getTrammen();
    for (size_t i = 0; i < trams.size() ; ++i) {
        Tram * huidigetram = trams [i];
        if (huidigetram->getHuidigeStation() == this){
            return huidigetram;
        }

    }
    return NULL;
}

