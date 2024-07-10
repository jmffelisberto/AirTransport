#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Airport.h"
#include "Airline.h"

class Graph {
public:
    void addAirport(const std::string &code);
    void addFlight(const std::string &source, const std::string &target, const std::string &airline);
    std::vector<std::string> getShortestPath(const std::string &start, const std::string &end, const std::unordered_set<std::string> &airlinePrefs);
    std::vector<std::string> getShortestPathAmongMultipleAirports(const std::vector<std::string> &source_airports, const std::vector<std::string> &target_airports, std::unordered_set<std::string> &airlinePrefs);
    std::vector<std::string> getCityAirports(const std::unordered_map<std::string, Airport>& airports, const std::string &city);
    void displayAirportNetwork(const std::string &airport, const std::unordered_map<std::string, Airline>& airlines);
    void displayDeparturesInfo(const std::string &airport, const std::unordered_map<std::string, Airport>& airports);
    void dfsLimitedDepth(const std::string &airport, int depth, std::unordered_set<std::string> &visited, std::unordered_set<std::string> &presentAirports, std::unordered_set<std::string> &presentCities, std::unordered_set<std::string> &presentCountries, const std::unordered_map<std::string, Airport> &airports);
    void displayAirportCoverage(const std::string &airport, int numFlights, const std::unordered_map<std::string, Airport> &airports);

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> adjList;
};

#endif