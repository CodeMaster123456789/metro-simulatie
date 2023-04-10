//
// Created by tigok on 17/03/2023.
//

#ifndef METRO_SIMULATIE_STATION_H
#define METRO_SIMULATIE_STATION_H
#include <string>

using namespace std;


class Station {
private:
    string naam;                                                    // hier zitten al de variabelen die nodig zijn voor Station
    Station * volgende;
    Station * vorige;
    int spoorNr;
public:
    Station();                                                      // dit zijn extra functies
    Station(string naam, int spoorNr);                              // die gebruiken we om onze output makelijker te laten printen
    void setSpoorNr(int spoor);
    int getSpoorNr();
    void setNaam(string naam);
    string getNaam();
    void setVolgende(Station * next);
    Station * getVolgende();
    void setVorige(Station * previous);
    Station * getVorige();
};


#endif //METRO_SIMULATIE_STATION_H
