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

/**
 * @brief stelt onze tram voor
 */
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
     *
     * REQUIRE(lijnNr >= 0, "LijnNr moet een positieve getal zijn");
     *
     * ENSURE(getLijnNr() == lijnNr, "lijnNR is correct ingestelt");
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

    void setBeginstation(Station * beginpunt);                      // Require niet nul, ensuire: getbeginstation is gelijk aan beginpunt
    Station * getBeginstation();                                    // geen Require, ensuire: Station is niet null
    void setHuidigeStation(Station * startpunt);                    // require: startpunt die nul is , ensuire: gethuidigestation is gelijk aan startpunt
    Station * getHuidigeStation();                                  // ensuire:
    string getType();                                               // ensuire:
    bool checkCompatible(Station * a);                              // require: en ensuire:
    virtual bool move();                                            // ensuire: true en false
    void reset();                                                   // ensuire:
};

class PCC:public Tram {

    int maxDefecten;                                            //TODO get en set maken voor de 4 int
    int aantalDefecten;
    int maxReparatieDuur;
    int reparatieDuur;

public:

    /**
     * Tram constructor
     *s
     * @param lijnNr lijnnummer van de tram
     *
     * REQUIRE(lijnNr >= 0, "LijnNr moet een positieve getal zijn");
     *
     * ENSURE(getLijnNr() == lijnNr, "lijnNR is correct ingestelt");
     *
     * ENSURE(this->beginStation == nullptr, "tram heeft geen beginstation");
     * ENSURE(this->huidigeStation == nullptr, "tram heeft geen huidigestation");
     *
     */

    PCC(int lijnNr);
     bool move();
    void setMaxDefecten(int d);
    void setMaxReparatieDuur(int r);
};

class Stadlijner:public Tram {
public:

    /**
     * Tram constructor
     *s
     * @param lijnNr lijnnummer van de tram
     *
     * REQUIRE(lijnNr >= 0, "LijnNr moet een positieve getal zijn");
     *
     * ENSURE(getLijnNr() == lijnNr, "lijnNR is correct ingestelt");
     *
     * ENSURE(this->beginStation == nullptr, "tram heeft geen beginstation");
     * ENSURE(this->huidigeStation == nullptr, "tram heeft geen huidigestation");
     *
     */

    Stadlijner(int lijnNr) : Tram(lijnNr) {
        type = "Stadslijner";
    }
};

class Albatros:public Tram {
public:

    /**
     * Tram constructor
     *s
     * @param lijnNr lijnnummer van de tram
     *
     * REQUIRE(lijnNr >= 0, "LijnNr moet een positieve getal zijn");
     *
     * ENSURE(getLijnNr() == lijnNr, "lijnNR is correct ingestelt");
     *
     * ENSURE(this->beginStation == nullptr, "tram heeft geen beginstation");
     * ENSURE(this->huidigeStation == nullptr, "tram heeft geen huidigestation");
     *
     */

    Albatros(int lijnNr) : Tram(lijnNr) {
        type = "Albatros";
    }
};

#endif //METRO_SIMULATIE_TRAM_H
