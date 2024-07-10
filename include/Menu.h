#ifndef MENU_H
#define MENU_H

#include <vector>
#include <unordered_set>
#include "Airport.h"
#include "Graph.h"

class Menu {
public:
    void displayMainMenu(const std::vector<Airport> &airports, Graph &graph);
    void displayBestFlightMenu(const std::vector<Airport> &airports, Graph &graph);
    void displayBestFlightByCityMenu(const std::vector<Airport> &airports, Graph &graph);
    void displayBestFlightByAirportMenu(const std::vector<Airport> &airports, Graph &graph);
    void displayInvalidChoice(const std::vector<Airport> &airports, Graph &graph);

private:
    std::unordered_set<std::string> getAirlinePreferences();
};

#endif // MENU_H
