#include "Graph.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm> 
#include "Airport.h"

void Graph::addAirport(const std::string &code) {
    if (adjList.find(code) == adjList.end()) {
        adjList[code] = std::vector<std::string>();
    }
}

void Graph::addFlight(const std::string &source, const std::string &target) {
    adjList[source].push_back(target);
}

std::vector<std::string> Graph::getShortestPath(const std::string &start, const std::string &end) {
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

        for (const auto &neighbor : adjList[airport]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                prev[neighbor] = airport;
            }
        }
    }

    return {};
}

std::vector<std::string> Graph::getShortestPathAmongMultipleAirports(const std::vector<std::string> &startAirports, const std::vector<std::string> &endAirports) {
    std::vector<std::string> shortestPath;
    int minPathLength = 9999999;

    for (const auto &start : startAirports) {
        for (const auto &end : endAirports) {
            std::vector<std::string> path = getShortestPath(start, end);
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
