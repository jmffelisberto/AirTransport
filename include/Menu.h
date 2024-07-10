#ifndef MENU_H
#define MENU_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Graph.h"
#include "Airport.h"
#include "Airline.h"

class Menu {
public:
    void displayMainMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines);
    void displayAirportInfoMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines, const std::string &airport);
    void displayBestFlightMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines);
    void displayBestFlightByCityMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines);
    void displayBestFlightByAirportMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines);
    void displayAirportID(const std::unordered_map<std::string, Airport> &airports, Graph &graph, const std::string &airport, std::unordered_map<std::string, Airline> &airlines);
    void displayInvalidChoice(const std::unordered_map<std::string, Airport> &airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines);
    std::unordered_set<std::string> getAirlinePreferences();
};

#endif