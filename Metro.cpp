#include "Metro.h"
#include "DesignByContract.h"
//-----------------------------------------
///   Metro
//-----------------------------------------

Metro::Metro() {
	_initCheck = this;
	reset();
	ENSURE(properlyInitialized(),
			"constructor must end in properlyInitialized state");
}

void Metro::reset() {
	REQUIRE(this->properlyInitialized(), "Metro wasn't initialized when calling setMoves");

	ENSURE(properlyInitialized(),
			"constructor must end in properlyInitialized state");
}


bool Metro::properlyInitialized() {
	return _initCheck == this;
}