//
// Created by tigok on 17/03/2023.
//

#ifndef METRO_SIMULATIE_STATION_H
#define METRO_SIMULATIE_STATION_H
#include <string>

using namespace std;


class Station {
private:
    string naam;
    Station * volgende;
    Station * vorige;
    int spoorNr;
public:
};


#endif //METRO_SIMULATIE_STATION_H
