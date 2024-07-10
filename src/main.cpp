#include <iostream>
#include "Reader.h"
#include "Graph.h"
#include "Menu.h"
using namespace std;

int main() {
    Graph graph;
    std::vector<Airport> airports = Reader::readAirports("../datasetcsv/airports.csv");
    std::vector<Airline> airlines = Reader::readAirlines("../datasetcsv/airlines.csv");
    std::vector<Flight> flights = Reader::readFlights("../datasetcsv/flights.csv", graph);
    //estratégia será por formar o grafo, i.e., "readFlights", dependendo de se o utilizador quer todas as companhias aéreas ou não

    Menu mainMenu;
    mainMenu.displayMainMenu(airports, graph);

    return 0;
}