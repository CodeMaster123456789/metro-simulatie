// Below are two lines serving as a so-called ``header guard''.
// Prevents from loading the same .h file multiple times
#ifndef MetroImporter_H
#define MetroImporter_H


#include <iostream>
#include "Metro.h"


enum SuccessEnum {ImportAborted, PartialImport, Success};


class MetroImporter {
public:

/**
// Read an XML description of a Metro simulatie from inStream.
// If errors occur, report them on errStream.
// Return whether succesful in the errorcode:
//	- ImportAborted = Metro simulatie is unchanged; reason for abortion is reported on errStream
//  - PartialImport = Some semantic errors reported on errStream;
//  - Succes = No importer errors; no errors reported
//\n REQUIRE(simulatie.properlyInitialized(), "Metro wasn't initialized");
//
*/
static SuccessEnum importMetro(const char * inputfilename, std::ostream& errStream, Metro& simulatie);

};



// Closing of the ``header guard''.
#endif