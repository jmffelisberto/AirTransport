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

    /* std::string start = "POM"; // Example start airport code
    std::string end = "OPO";   // Example end airport code
 */
    //std::vector<std::string> path = graph.getShortestPath(start, end);

    /* if (!path.empty()) {
        std::cout << "Shortest path from " << start << " to " << end << ":\n";
        for (const auto &airport : path) {
            std::cout << airport << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found from " << start << " to " << end << std::endl;
    } */

    Menu mainMenu;
    mainMenu.displayMainMenu();

    return 0;
}
