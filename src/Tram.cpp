//
// Created by tigok on 20/03/2023.
//

#include "Tram.h"

Tram::Tram(int l, int s) {
    this->lijnNr = l;
    this->snelheid = s;
    this->beginStation = nullptr;
    this->huidigeStation = nullptr;
}

Tram::Tram() {
    this->lijnNr = -1;
    this->snelheid = -1;
    this->beginStation = nullptr;
    this->huidigeStation = nullptr;
}

void Tram::setLijnNr(int lijn) {
    this->lijnNr = lijn;
}

int Tram::getLijnNr() {
    return this->lijnNr;
}

void Tram::setSnelheid(int km_h) {
    this->snelheid = km_h;
}

int Tram::getSnelheid() {
    return this->snelheid;
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
