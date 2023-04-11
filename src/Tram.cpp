//
// Created by tigok on 20/03/2023.
//

#include "Tram.h"
#include "Station.h"
#include "Metro.h"

Metro * Tram::sim = nullptr;

Tram::Tram(int lijnNr, int aantalDefecten, int reparatieTijd) {
    this->lijnNr = lijnNr;
    this->beginStation = nullptr;
    this->huidigeStation = nullptr;
    this->maxDefecten = aantalDefecten;
    this->maxReparatieDuur = reparatieTijd;
}

Tram::Tram() {
    this->lijnNr = -1;
    this->beginStation = nullptr;
    this->huidigeStation = nullptr;
}

void Tram::setLijnNr(int lijn) {
    this->lijnNr = lijn;
}

int Tram::getLijnNr() {
    return this->lijnNr;
}

int Tram::getSnelheid() {
    if (this->type == "PCC") {
        return 40;
    }
    else {
        return 70;
    }
}

void Tram::setBeginstation(Station *beginpunt) {
    this->beginStation = beginpunt;
}

Station *Tram::getBeginstation() {
    return this->beginStation;
}

void Tram::setHuidigeStation(Station *startpunt) {
    this->huidigeStation = startpunt;
}

Station *Tram::getHuidigeStation() {
    return this->huidigeStation;
}

void Tram::setType(string t) {
    this->type = t;
}

string Tram::getType() {
    return this->type;
}

bool Tram::checkCompatible(Station *a) {
    if (this->getType() != "PCC" and a->getType() == "Halte") {
        return false;
    }
    else {
        return true;
    }
}

Station *Tram::getNextValidStation() {
    Station * kandidaat = this->getHuidigeStation()->getVolgende();
    while (checkCompatible(kandidaat) == false) {
        kandidaat = kandidaat->getVolgende();
    }
    return kandidaat;
}

bool Tram::padIsVrij(Station *k) {
    Station * huidige = this->getHuidigeStation()->getVolgende();
    while (huidige != k->getVolgende()) {
        if (huidige->getHuidigeTram() != nullptr) {
            return false;
        }
        huidige = huidige->getVolgende();
    }
    return true;
}

bool Tram::move() {

    if (reparatieDuur > 0) {
        reparatieDuur--;
        return false;
    }

    Station * kandidaat = getNextValidStation();
    bool padVrij = padIsVrij(kandidaat);
    if (padVrij) {
        cout << "Tram " << this->getLijnNr() << " reed van Station " << getHuidigeStation()->getNaam() << " naar Station " << kandidaat->getNaam() << endl;
        setHuidigeStation(kandidaat);
        aantalDefecten++;

        if (aantalDefecten == maxDefecten) {
            aantalDefecten = 0;
            reparatieDuur = maxReparatieDuur;
        }

        return true;
    }
    else {
        return false;
    }
}

void Tram::reset() {
    huidigeStation = beginStation;
}

void Tram::setMaxDefecten(int d) {
    maxDefecten = d;
}

void Tram::setMaxReparatieDuur(int r) {
    maxReparatieDuur = r;
}
