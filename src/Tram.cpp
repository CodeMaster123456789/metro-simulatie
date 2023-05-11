//
// Created by tigok on 20/03/2023.
//

#include "Tram.h"
#include "Station.h"
#include "Metro.h"
#include "../lib/DesignByContract.h"

Metro * Tram::sim = nullptr;

Tram::Tram(int lijnNr, int aantalDefecten, int reparatieTijd) {

    REQUIRE(lijnNr >= 0, "LijnNr moet een positieve getal zijn");
    REQUIRE(aantalDefecten != 0, "aantaldefecten mag niet 0 zijn");
    REQUIRE(reparatieTijd >= 0, "reparatietijd mag niet negatief zijn");

    this->lijnNr = lijnNr;
    this->beginStation = nullptr;
    this->huidigeStation = nullptr;
    this->maxDefecten = aantalDefecten;
    this->maxReparatieDuur = reparatieTijd;

    ENSURE(this->lijnNr == lijnNr, "lijnNR is correct ingestelt");
    ENSURE(this->maxDefecten == aantalDefecten, "maxDefecten is correct ingestelt");
    ENSURE(this->maxReparatieDuur == reparatieTijd, "maxReparatieDuur is correct ingestelt");
    ENSURE(this->beginStation == nullptr, "tram heeft geen beginstation");
    ENSURE(this->huidigeStation == nullptr, "tram heeft geen huidigestation");

}

Tram::Tram() {

    this->lijnNr = -1;
    this->beginStation = nullptr;
    this->huidigeStation = nullptr;

    ENSURE(this->lijnNr == -1,"lijnNr heeft een standaard constante -1");
    ENSURE(this->beginStation == nullptr, "tram heeft geen beginstation");
    ENSURE(this->huidigeStation == nullptr, "tram heeft geen huidigestation");
}

void Tram::setLijnNr(int lijn) {

    REQUIRE(lijn >= 0,"lijn is de nummer van de tram");

    this->lijnNr = lijn;

    ENSURE(this->lijnNr == lijn,"lijn moet een positieve getal hebben");
}

int Tram::getLijnNr() {

    return this->lijnNr;

    ENSURE(this->lijnNr == lijnNr,"krijgt het nummer van de tram terug");
}

int Tram::getSnelheid() {

    if (this->type == "PCC") {
        return 40;
    }
    else {
        return 70;
    }

    ENSURE(this->type == type,"krijgt de snelheid van de tram bepaalt door de type");
}

void Tram::setBeginstation(Station *beginpunt) {

    REQUIRE(beginpunt,"beginpunt is waar de vertrekpunt is van de tram");

    this->beginStation = beginpunt;

    ENSURE(this->beginStation = beginpunt,"dit zal ook de start zijn van de tram");
}

Station *Tram::getBeginstation() {

    return this->beginStation;

    ENSURE(this->beginStation = beginStation,"krijgt de beginstation terug");
}

void Tram::setHuidigeStation(Station *startpunt) {

    REQUIRE(startpunt,"dit is de station waar de tram gelegen is");

    this->huidigeStation = startpunt;

    ENSURE(this->huidigeStation = startpunt,"de huidige station is de plek waar de tram nu gelegen is");
}

Station *Tram::getHuidigeStation() {

    return this->huidigeStation;

    ENSURE(this->huidigeStation = huidigeStation,"krijgt de huidige station terug");
}

void Tram::setType(string t) {

    REQUIRE(t == "PCC" or t == "Stadslijner" or t == "Albatros","dit is een type van een tram");

    this->type = t;

    ENSURE(this->type == t,"de tram heeft maar 3 types");
}

string Tram::getType() {

    return this->type;

    ENSURE(this->type == type,"krijgt de type van de tram terug");
}

bool Tram::checkCompatible(Station *a) {

    REQUIRE(a,"a kan 2 dingen zijn ofwel een station ofwel een halte");


    if (this->getType() != "PCC" and a->getType() == "Halte") {
        return false;
    }
    else {
        return true;
    }

    ENSURE(a,"indien a een halte is dan kan alleen een PCC daar een stop maken");

}

Station *Tram::getNextValidStation() {

    Station * kandidaat = this->getHuidigeStation()->getVolgende();
    while (checkCompatible(kandidaat) == false) {
        kandidaat = kandidaat->getVolgende();
    }
    return kandidaat;

    ENSURE(this->getHuidigeStation() == kandidaat,"als de kandidaat een PCC is in een halte dan kan bv een albatros niet naar de volgende station gaan");
}

bool Tram::padIsVrij(Station *k) {

    REQUIRE(k,"k is een station dat moet vermeld worden of de station vrij is");

    Station * huidige = this->getHuidigeStation()->getVolgende();
    while (huidige != k->getVolgende()) {
        if (huidige->getHuidigeTram() != nullptr) {
            return false;
        }
        huidige = huidige->getVolgende();
    }
    return true;

    ENSURE(k,"indien k niet vrij is omdat PCC voor een albatros staat omdat de PCC in een halte is moet die wachten");
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

    ENSURE(padVrij == true,"de tram kan bewegen naar de volgende station");
    ENSURE(padVrij == false,"de tram kan niet bewegen naar de volgende station");
}

void Tram::reset() {

    huidigeStation = beginStation;

    ENSURE(huidigeStation == beginStation,"het zorgt ervoor dat de beginstation gereset wordt als de huidigestation");
}

void Tram::setMaxDefecten(int d) {

    REQUIRE(d >= 0,"dit moet een positieve getal zijn mag zelf ook 0 zijn");

    maxDefecten = d;

    ENSURE(maxDefecten == d,"het maximaal aantal keren dat de tram in panne mag vallen");
}

void Tram::setMaxReparatieDuur(int r) {

    REQUIRE(r >= 0,"dit moet een positieve getal zijn mag zelf ook 0 zijn");

    maxReparatieDuur = r;

    ENSURE(maxReparatieDuur == r,"het maximaal aantal  stappen van de simulatie de tram moet wachten");
}
