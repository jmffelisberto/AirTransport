#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Airport.h"

class Graph {
public:
    struct FlightInfo {
        std::string target;
        std::string airline;
    };

    void addAirport(const std::string &code);
    void addFlight(const std::string &source, const std::string &target, const std::string &airline);
    std::vector<std::string> getShortestPath(const std::string &start, const std::string &end, const std::unordered_set<std::string> &airlines = {});
    std::vector<std::string> getShortestPathAmongMultipleAirports(const std::vector<std::string> &source_airports, const std::vector<std::string> &target_airports, const std::unordered_set<std::string> &airlines = {});
    std::vector<std::string> getCityAirports(const std::vector<Airport> &airports, const std::string &city);

private:
    std::unordered_map<std::string, std::vector<FlightInfo>> adjList;
};

#endif // GRAPH_H
