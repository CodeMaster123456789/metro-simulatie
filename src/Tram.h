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
private:
    int lijnNr;
    Station * beginStation;
    Station * huidigeStation;
    string type;
    int maxDefecten = -1;
    int aantalDefecten = 0;
    int maxReparatieDuur = 0;
    int reparatieDuur = 0;
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
     * ENSURE(this->lijnNr == lijnNr, "lijnNR is correct ingestelt");
     * ENSURE(this->maxDefecten == aantalDefecten, "maxDefecten is correct ingestelt");
     * ENSURE(this->maxReparatieDuur == reparatieTijd, "maxReparatieDuur is correct ingestelt");
     * ENSURE(this->beginStation == nullptr, "tram heeft geen beginstation");
     * ENSURE(this->huidigeStation == nullptr, "tram heeft geen huidigestation");
     *
     */

    Tram(int lijnNr, int aantalDefecten = -1, int reparatieTijd = 0);                                         // ectra functies die ik ga gebruiken voor de variabelen.

    /**
    * Tram constructor zonder een argument
    * ENSURE(this->lijnNr == lijnNr,"lijnNr heeft een standaard constante -1")
    * ENSURE(this->beginStation == nullprt,"tram heeft geen beginstation")
    * ENSURE(this->huidigeStation == nullprt,"tram heeft geen huidigeStation")
    */

    Tram();

    /**
     *
     * @return lijnNr nummer van de lijn
     */

    void setLijnNr(int lijn);

    /**
     *
     * @return lijnNr nummer van de lijn
     */

    int getLijnNr();

    /**
     *
     * @return lijnNr nummer van de lijn
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
    void setType(string type);
    string getType();
    bool checkCompatible(Station * a);
    bool move();
    void reset();
    void setMaxDefecten(int d);
    void setMaxReparatieDuur(int r);
};


#endif //METRO_SIMULATIE_TRAM_H
