#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include "Airport.h"

class Graph {
public:
    void addAirport(const std::string &code);
    void addFlight(const std::string &source, const std::string &target);

    std::vector<std::string> getShortestPath(const std::string &start, const std::string &end);
    std::vector<std::string> getShortestPathAmongMultipleAirports(const std::vector<std::string> &startAirports, const std::vector<std::string> &endAirports);
    std::vector<std::string> getCityAirports(const std::vector<Airport> &airports, const std::string &city);

private:
    std::unordered_map<std::string, std::vector<std::string>> adjList;
};

#endif // GRAPH_H
