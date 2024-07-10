#include "Graph.h"
#include "Airport.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

void Graph::addAirport(const std::string &code) {
    if (adjList.find(code) == adjList.end()) {
        adjList[code] = std::vector<FlightInfo>();
    }
}

void Graph::addFlight(const std::string &source, const std::string &target, const std::string &airline) {
    adjList[source].push_back({target, airline});
}

std::vector<std::string> Graph::getShortestPath(const std::string &start, const std::string &end, const std::unordered_set<std::string> &airlines) {
    std::unordered_map<std::string, std::string> prev;
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        std::string airport = q.front();
        q.pop();

        if (airport == end) {
            std::vector<std::string> path;
            for (std::string at = end; at != ""; at = prev[at]) {
                path.push_back(at);
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const auto &flight : adjList[airport]) {
            if (airlines.empty() || airlines.find(flight.airline) != airlines.end()) {
                if (visited.find(flight.target) == visited.end()) {
                    q.push(flight.target);
                    visited.insert(flight.target);
                    prev[flight.target] = airport;
                }
            }
        }
    }

    return {};
}

std::vector<std::string> Graph::getShortestPathAmongMultipleAirports(const std::vector<std::string> &source_airports, const std::vector<std::string> &target_airports, const std::unordered_set<std::string> &airlines) {
    std::vector<std::string> shortestPath;
    int minPathLength = 99999999;

    for (const auto &source : source_airports) {
        for (const auto &target : target_airports) {
            std::vector<std::string> path = getShortestPath(source, target, airlines);
            if (!path.empty() && path.size() < minPathLength) {
                minPathLength = path.size();
                shortestPath = path;
            }
        }
    }

    return shortestPath;
}

std::vector<std::string> Graph::getCityAirports(const std::vector<Airport> &airports, const std::string &city) {
    std::vector<std::string> cityAirports;
    for (const auto &airport : airports) {
        if (airport.city == city) {
            cityAirports.push_back(airport.code);
        }
    }
    return cityAirports;
}