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
     *
     * REQUIRE(beginpunt,"beginpunt is waar de vertrekpunt is van de tram")
     *
     * ENSURE(this->beginStation = beginpunt,"dit zal ook de start zijn van de tram")
     */

    void setBeginstation(Station * beginpunt);                      // Require niet nul, ensuire: getbeginstation is gelijk aan beginpunt

    /**
     *
     * @return beginstation
     *
     * ENSURE(getBeginstation() == beginStation,"krijgt de beginstation terug")
     */

    Station * getBeginstation();                                    // geen Require, ensuire: Station is niet null

    /**
     *
     * @param startpunt dit is de punt vanwaar de tram zal starten met te bewegen
     *
     * REQUIRE(startpunt,"dit is de station waar de tram gelegen is")
     *
     * ENSURE(this->huidigeStation = startpunt,"de huidige station is de plek waar de tram nu gelegen is")
     */

    void setHuidigeStation(Station * startpunt);                    // require: startpunt die nul is , ensuire: gethuidigestation is gelijk aan startpunt

    /**
     *
     * @return huidigeStation geef jouw de huidigestation weer
     *
     * ENSURE(this->huidigeStation = huidigeStation,"krijgt de huidige station terug")
     */

    Station * getHuidigeStation();                                  // ensuire:

    /**
     *
     * @return type: geeft weer wat de type is van de tram
     *
     * ENSURE(this->type == type,"krijgt de type van de tram terug")
     */

    string getType();                                               // ensuire:

    /**
     *
     * @param a de station die geldig is voor de gegeven tram
     * @return true: de station waar de tram naartoe gaat is toegestaan.
     * @return false: de station waar de tram naartoe gaat is niet toegestaan.
     */

    bool checkCompatible(Station * a);                              // require: en ensuire:

    /**
     *
     * @return true: de tram is toegestaan om zich te bewegen
     * @return false: de tram is niet toegestaan om zich te bewegen
     *
     * ENSURE(padVrij == true,"de tram kan bewegen naar de volgende station")
     * ENSURE(padVrij == false,"de tram kan niet bewegen naar de volgende station")
     */

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
