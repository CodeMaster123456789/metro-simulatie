#include "DesignByContract.h"
#include "MetroExporter.h"

using namespace std;


MetroExporter::MetroExporter() {
	_initCheck = this;
    ENSURE(properlyInitialized(),
			"constructor must end in properlyInitialized state");
}


bool MetroExporter::properlyInitialized() {
	return _initCheck == this;
}