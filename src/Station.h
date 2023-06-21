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

    Station();                                                      // ensuire:
    Station(string naam, int spoorNr);                              // Require en ensuire
    void setSpoorNr(int spoor);                                     // require en insuire
    int getSpoorNr();                                               // insuire
    void setNaam(string naam);                                      // require en insuire
    string getNaam();                                               // insuire
    void setVolgende(Station * next);                               // require en insuire
    Station * getVolgende();                                        // insuire
    void setVorige(Station * previous);                             // require en insuire
    Station * getVorige();                                          // insuire
    string getType();                                               // insuire
    Tram *getHuidigeTram();                                         // insuire

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
