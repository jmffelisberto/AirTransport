#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Airport.h"

class Menu {
public:

    void displayMainMenu(std::vector<Airport> airports);
    void displayBestFlightMenu(std::vector<Airport> airports);
    void displayBestFlightByCityMenu(std::vector<Airport> airports);
    void displayBestFlightByAirportMenu(std::vector<Airport> airports);
    void displayAirportInformationMenu(std::vector<Airport> airports);
    void displayInvalidChoice(std::vector<Airport> airports);

};

#endif // MENU_H