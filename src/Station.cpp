//
// Created by tigok on 17/03/2023.
//

#include "Station.h"
#include "Metro.h"
#include "../lib/DesignByContract.h"

Metro * Station::sim = NULL;

Station::Station() {                                                    // deze gegevens zet ik als mijn defaults.

    REQUIRE(this->getNaam() == "", "dit moet de naam van de Station zijn");
    REQUIRE(this->getSpoorNr() >= 0, "de nummer van de spoorlijn");

    this->naam = "";
    this->spoorNr = -1;
    this->volgende = NULL;
    this->vorige = NULL;

    ENSURE(getNaam() == "", "dit wordt de naam van de Station");
    ENSURE(getSpoorNr() == spoorNr, "dit wordt de nummer van de spoor");
    ENSURE(getVolgende() == NULL, "de volgende zal door middel van de gegeven de tram de volgende halte weergeven");
    ENSURE(getVorige() == NULL, "de vorige zal door middel van de gegeven tram de vorige weergeven");

}

Station::Station(string naam, int spoorNr) {                            // hier geeft ik de gegevens een beginwaarde weer.

    REQUIRE(this->getNaam() == naam, "de naam van de tram");
    REQUIRE(this->getSpoorNr() == spoorNr, "de nummer van de spoor");

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

    REQUIRE(getSpoorNr() == spoor, "dit is de nummer van de spoor");

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

void Station::setVolgende(Station *next) {                              // hier zeg ik dat next mijn argument is voor naam.
    this->volgende = next;

    ENSURE(getVorige() == next, "dit geeft jouw de Station die de tram nog moet paseren");

}

Station *Station::getVolgende() {                                       // Als ik dit oproep geeft het mij de text voor volgende weer.
    return this->volgende;

    ENSURE(getVolgende() == volgende, "dit geeft jouw de volgende halte weer");

}

void Station::setVorige(Station *previous) {                            // hier zeg ik dat previous mijn argument is voor vorige.
    this->vorige = previous;

    ENSURE(getVorige() == previous, "dit geeft u de gepaseerde station weer");
}

Station *Station::getVorige() {                                         // Als ik dit oproep geeft het mij de text voor vorige weer.
    return this->vorige;

    ENSURE()

}

string Station::getType() {
    return this->type;
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

