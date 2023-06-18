//
// Created by tigok on 20/03/2023.
//

#ifndef METRO_SIMULATIE_TRAM_H
#define METRO_SIMULATIE_TRAM_H
#include <iostream>
#include <vector>
#include <string>

class Station;
class Metro;

using namespace std;


class Tram {
    // hier geef ik alle variabelen weer voor Tram
protected:
    int lijnNr;
    Station * beginStation;
    Station * huidigeStation;
    string type;
    Station * getNextValidStation();
    bool padIsVrij(Station *k);
public:

    static Metro * sim;

    /**
     * Tram constructor
     *s
     * @param lijnNr lijnnummer van de tram
     * @param aantalDefecten om de hoeveel station valt de tram in panne,als dit negatief is valt de tram nooit in panne
     * @param reparatieTijd na hoeveel tijd is de tram gerepareerd
     *
     * REQUIRE(lijnNr >= 0, "LijnNr moet een positieve getal zijn");
     * REQUIRE(aantalDefecten != 0, "aantaldefecten mag niet 0 zijn");
     * REQUIRE(reparatieTijd >= 0, "reparatietijd mag niet negatief zijn");
     *
     * ENSURE(getLijnNr() == lijnNr, "lijnNR is correct ingestelt");
     * ENSURE(this->maxDefecten == aantalDefecten, "maxDefecten is correct ingestelt");
     * ENSURE(this->maxReparatieDuur == reparatieTijd, "maxReparatieDuur is correct ingestelt");
     * ENSURE(this->beginStation == nullptr, "tram heeft geen beginstation");
     * ENSURE(this->huidigeStation == nullptr, "tram heeft geen huidigestation");
     *
     */

    Tram(int lijnNr);                                         // ectra functies die ik ga gebruiken voor de variabelen.

    /**
    * Tram constructor zonder een argument
    * ENSURE(this->lijnNr == lijnNr,"lijnNr heeft een standaard constante -1")
    * ENSURE(this->beginStation == nullprt,"tram heeft geen beginstation")
    * ENSURE(this->huidigeStation == nullprt,"tram heeft geen huidigeStation")
    */

    Tram();

    /**
     *
     * @param lijn de nummer van de tram
     *
     * REQUIRE(lijn <= 0,lijn is de nummer van de tram)
     */

    void setLijnNr(int lijn);

    /**
     *
     * @return lijnNr nummer van de lijn
     */

    int getLijnNr();

    /**
     *
     * @return getLijnNr == lijnNr
     */

    int getSnelheid();

    /**
     *
     * @param beginpunt
     */

    void setBeginstation(Station * beginpunt);
    Station * getBeginstation();
    void setHuidigeStation(Station * startpunt);
    Station * getHuidigeStation();
    string getType();
    bool checkCompatible(Station * a);
    virtual bool move();
    void reset();
};

class PCC:public Tram {

    int maxDefecten;                                            //TODO get en set maken voor de 4 int
    int aantalDefecten;
    int maxReparatieDuur;
    int reparatieDuur;

public:
    PCC(int lijnNr);
     bool move();
    void setMaxDefecten(int d);
    void setMaxReparatieDuur(int r);
};

class Stadlijner:public Tram {
public:
    Stadlijner(int lijnNr) : Tram(lijnNr) {
        type = "Stadslijner";
    }
};

class Albatros:public Tram {
public:
    Albatros(int lijnNr) : Tram(lijnNr) {
        type = "Albatros";
    }
};

#endif //METRO_SIMULATIE_TRAM_H
