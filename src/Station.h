//
// Created by tigok on 17/03/2023.
//

#ifndef METRO_SIMULATIE_STATION_H
#define METRO_SIMULATIE_STATION_H
#include <string>
#include "Tram.h"

using namespace std;
class Metro;

class Station {
protected:
    string naam;                                                    // hier zitten al de variabelen die nodig zijn voor Station
    Station * volgende;
    Station * vorige;
    int spoorNr;
    string type;
public:

    static Metro * sim;

    /**
     *ENSURE(getNaam() == "", "dit wordt de naam van de Station");
     * ENSURE(getSpoorNr() == spoorNr, "dit is een standaard waarde");
     * ENSURE(getVolgende() == NULL, "de volgende zal door middel van de gegeven de tram de volgende halte weergeven");
     * ENSURE(getVorige() == NULL, "de vorige zal door middel van de gegeven tram de vorige weergeven");
     */

    Station();                                                      // ensuire:

    /**
     *
     * @param naam dit is een string die een naam voorstelt van de station
     * @param spoorNr dit een nummer voor de spoornummer
     *
     * REQUIRE(spoorNr >= 0, "de nummer van de spoor");
     * REQUIRE(naam == "","een naam voor de station zelf");
     *
     * ENSURE(getNaam() == naam, "dit is de naam van de tram");
     * ENSURE(getSpoorNr() == spoorNr, "dit is de nummer van de spoor");
     * ENSURE(getVolgende() == NULL, "dit geeft de volgende halte weer");
     * ENSURE(getVorige() == NULL, "dit geeft de vorige halte weer");
     */

    Station(string naam, int spoorNr);

    /**
     *
     * @param spoor dit is een getal die de nummer voorstelt van de spoor
     *
     * REQUIRE(getSpoorNr() >= 0, "het getal moet niet negatief zijn");
     *
     * ENSURE(getSpoorNr() == spoor, "het geeft jou de nummer van de spoor weer");
     */

    void setSpoorNr(int spoor);

    /**
     *
     * @return spoorNr het geefr je de nummer van de spoor
     *
     * REQUIRE(getNaam() == "", "een naam voor de Station");
     *
     * ENSURE(getNaam() == naam, "dit geeft jouw de naam weer van de Station");
     */

    int getSpoorNr();
    void setNaam(string naam);

    /**
     *
     * @return name de naam van de station
     *
     * REQUIRE(getNaam() == "", "een naam voor de Station");
     *
     * ENSURE(getNaam() == naam, "dit geeft jouw de naam weer van de Station");
     */

    string getNaam();

    /**
     *
     * @param next dit is de variable die de volgende station weergeeft
     *
     * REQUIRE(next == volgende, "de next is de volgende station van de gegeven huidige station");
     *
     * ENSURE(getVolgende() == next, "dit geeft jouw de Station die de tram nog moet paseren");
     */

    void setVolgende(Station * next);

    /**
     *
     * @return volgende: de volgende station
     *
     * ENSURE(getVolgende() == volgende, "dit geeft jouw de volgende halte weer");
     */

    Station * getVolgende();

    /**
     *
     * @param previous dit is de vorige station die de tram bezocht
     *
     * REQUIRE(previous,"dit geeft de vorige station weer");
     *
     * ENSURE(vorige == previous, "dit geeft u de gepaseerde station weer");
     */

    void setVorige(Station * previous);

    /**
     *
     * @return previous: de bezocht station door de tram
     *
     * REQUIRE(previous,"dit geeft de vorige station weer");
     *
     *  ENSURE(vorige == previous, "dit geeft u de gepaseerde station weer");
     */

    Station * getVorige();

    /**
     *
     * @return vorige de bezochte station
     *
     * ENSURE(getVorige() == vorige,"de vorige geeft jouw de bezochte station weer");
     */

    string getType();

    /**
     *
     * @return type: de type van de tram
     *
     * ENSURE(getType() == type, "het geeft jouw de type van de tram");
     */

    Tram *getHuidigeTram();

};

class Halte:public Station{                                                 // neem de require en ensuire over van station
public:
    Halte():Station() {
        type = "Halte";
    }
    Halte(string naam, int spoorNr):Station(naam,spoorNr) {
        type = "Halte";
    }
};

class Metrostation:public Station{
public:
    Metrostation():Station() {
        type = "Metrostation";
    }
    Metrostation(string naam, int spoorNr):Station(naam,spoorNr) {
        type = "Metrostation";
    }
};

#endif //METRO_SIMULATIE_STATION_H
