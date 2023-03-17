// Below are two lines serving as a so-called ``header guard''.
// Prevents from loading the same .h file multiple times
#ifndef Metro_H
#define Metro_H


#include <iostream>


class Metro; // forward declaration


class Metro {
public:
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

};


// Closing of the ``header guard''.
#endif