// Below are two lines serving as a so-called ``header guard''.
// Prevents from loading the same .h file multiple times
#ifndef Metro_H
#define Metro_H


#include <iostream>
#include "vector"

#include "Station.h"
#include "Tram.h"

using namespace std;

class Metro {
public:

    /**
     *
     * @param s
     *
     * REQUIRE(s,"een variable voor een station");
     *
     * ENSURE(s == new Station,"s is een nieuw station en wordt toegevoegd");
     */
    void addStation(Station * s);

    /**
     *
     * @param naam: de naam van de station
     * @return s: de string naam die op basis daarvan de station zoekt
     * @return NULL: geeft aan dat er geen station met de gegeven naar is gevonden
     *
     * REQUIRE(naam == "","deze naam wordt gebruikt om mee te zoeken");
     *
     * ENSURE(naam == ""," "" staat voor de naam van de station die we willen vinden en indien het s is bestaat die station");
     */
    Station * findStation(string naam);

    /**
     *
     * @param t variable voor een tram die wordt toegevoegd in de lijst met trammen
     *
     * REQUIRE(t,"dit is een variable voor een nieuwe tram");
     *
     * ENSURE(t == new Tram,"t is een nieuwe tram die is toegevoed in de tram lijst")
     */
    void addTram(Tram * t);

    /**
     *
     * @return stationen: een lijst met al de stationen
     *
     * ENSURE(getStationen() == stationen,"het geeft jouw de lijst met al de beschikbare stations")
     */
    const vector<Station *> & getStationen();

    /**
     *
     * @return trammen: een lijst met al de trammen
     *
     * ENSURE(getTrammen() == trammen,"het geeft jouw een lijst weer met al de beschikbare trammen")
     */
    const vector<Tram *> & getTrammen();

    void moveTrams();

    /**
     *
     * @return tijdstip: geeft jouw de tijd weer
     *
     * ENSURE(getTijd() == tijdstip,"het geeft jouw de tijdstip weer");
     */

    int getTijd();

    /**
     *
     * @param eindtijd: dit is de tijd waarmee bedoelt wordt hoeveel halte nog de andere trammen moeten wachten om verder te kunnen gaan naar de andere bestemming
     *
     * REQUIRE(eindtijd >= 0,"moet geen negatief getal zijn");
     *
     * ENSURE(eindtijd == tijdstip, "door de gegeven eindtijd houd de simulatie rekening mee hoeveel stappen er worden genomen");
     */

    void simulate(int eindtijd);

/**
\n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
*/
	Metro();

	bool properlyInitialized();

/**
\n REQUIRE(this->properlyInitialized(), "Metro wasn't initialized when calling reset");
\n ENSURE(properlyInitialized(), "reset must end in properlyInitialized state");
*/
	void reset();

private:
	Metro * _initCheck; //!use pointer to myself to verify whether I am properly initialized
	vector<Station *> stationen;
    vector<Tram *> trammen;
    int tijdstip;
};


// Closing of the ``header guard''.
#endif