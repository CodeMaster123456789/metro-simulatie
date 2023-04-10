//
// Created by tigok on 20/03/2023.
//

#ifndef METRO_SIMULATIE_TRAM_H
#define METRO_SIMULATIE_TRAM_H
#include <iostream>
#include <vector>
#include <string>
#include "Station.h"

using namespace std;


class Tram {                                                                // hier geef ik alle variabelen weer voor Tram
private:
    int lijnNr;
    int snelheid;
    Station * beginStation;
    Station * huidigeStation;
    string type;
public:
    Tram(int lijnNr, int snelheid);                                         // ectra functies die ik ga gebruiken voor de variabelen.
    Tram();
    void setLijnNr(int lijn);
    int getLijnNr();
    void setSnelheid(int km_h);
    int getSnelheid();
    void setBeginstation(Station * beginpunt);
    Station * getBeginstation();
    void setHuidigeStation(Station * startpunt);
    Station * getHuidigeStation();
    void setType(string type);
    string getType();
};


#endif //METRO_SIMULATIE_TRAM_H
