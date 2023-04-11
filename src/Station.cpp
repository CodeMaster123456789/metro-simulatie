//
// Created by tigok on 17/03/2023.
//

#include "Station.h"
#include "Metro.h"

Metro * Station::sim = nullptr;

Station::Station() {                                                    // deze gegevens zet ik als mijn defaults.
    this->naam = "";
    this->spoorNr = -1;
    this->volgende = nullptr;
    this->vorige = nullptr;
}

Station::Station(string naam, int spoorNr) {                            // hier geeft ik de gegevens een beginwaarde weer.
    this->naam = naam;
    this->spoorNr = spoorNr;
    this->volgende = nullptr;
    this->vorige = nullptr;
}

void Station::setSpoorNr(int spoor) {                                   // hier noem ik spoor als het argument voor spoorNr.
    this->spoorNr = spoor;
}

int Station::getSpoorNr() {                                             // Als ik dit oproep geeft het mij het nodige getal voor spoorNr.
    return this->spoorNr;
}

void Station::setNaam(string name) {                                    // hier zeg ik dat name mijn argument is voor naam.
    this->naam = name;
}

string Station::getNaam() {                                             // Als ik dit oproep geeft het mij de text voor naam weer.
    return this->naam;
}

void Station::setVolgende(Station *next) {                              // hier zeg ik dat next mijn argument is voor naam.
    this->volgende = next;
}

Station *Station::getVolgende() {                                       // Als ik dit oproep geeft het mij de text voor volgende weer.
    return this->volgende;
}

void Station::setVorige(Station *previous) {                            // hier zeg ik dat previous mijn argument is voor vorige.
    this->vorige = previous;
}

Station *Station::getVorige() {                                         // Als ik dit oproep geeft het mij de text voor vorige weer.
    return this->vorige;
}

void Station::setType(string t) {
    this->type = t;
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
    return nullptr;
}

