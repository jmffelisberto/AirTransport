#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>

class Graph {
public:
    void addAirport(const std::string &code);
    void addFlight(const std::string &source, const std::string &target);

    std::vector<std::string> getShortestPath(const std::string &start, const std::string &end);

private:
    std::unordered_map<std::string, std::vector<std::string>> adjList;
};

#endif // GRAPH_H
