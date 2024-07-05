#ifndef MENU_H
#define MENU_H

#include <iostream>

class Menu {
public:

    void displayMainMenu();
    void displayBestFlightMenu();
    void displayBestFlightByCityMenu();
    void displayBestFlightByAirportMenu();
    void displayAirportInformationMenu();
    void displayInvalidChoice();

};

#endif // MENU_H