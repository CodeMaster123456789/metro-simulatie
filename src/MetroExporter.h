// Below are two lines serving as a so-called ``header guard''.
// Prevents from loading the same .h file multiple times
#ifndef MetroExporter_H
#define MetroExporter_H


#include <iostream>
#include "Metro.h"


class MetroExporter {
public:

/**
\n ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state.");
\n REQUIRE(! this->documentStarted(), "After constructor a MetroExporter is *not* in the documentStarted state.");
*/
	MetroExporter ();

	bool properlyInitialized();
    void simpleUitvoer(const char *pad, Metro & simulatie);
    static void tramMoved(Tram * t,Station * s);

private:
	MetroExporter * _initCheck; //!use pointer to myself to verify whether I am properly initialized

};

// Closing of the ``header guard''.
#endif