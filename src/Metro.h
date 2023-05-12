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
     */
    void addStation(Station * s);

    /**
     *
     * @param naam
     * @return
     */
    Station * findStation(string naam);

    /**
     *
     * @param t
     */
    void addTram(Tram * t);

    /**
     *
     * @return
     */
    const vector<Station *> & getStationen();

    /**
     *
     * @return
     */
    const vector<Tram *> & getTrammen();

    void moveTrams();

    int getTijd();

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