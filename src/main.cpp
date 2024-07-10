#include <iostream>
#include "Reader.h"
#include "Graph.h"
#include "Menu.h"

using namespace std;

int main() {
    Graph graph;
    std::unordered_map<std::string, Airport> airports = Reader::readAirports("../datasetcsv/airports.csv");
    std::unordered_map<std::string, Airline> airlines = Reader::readAirlines("../datasetcsv/airlines.csv");
    std::vector<Flight> flights = Reader::readFlights("../datasetcsv/flights.csv", graph);

    Menu mainMenu;
    mainMenu.displayMainMenu(airports, graph, airlines);

    return 0;
}
