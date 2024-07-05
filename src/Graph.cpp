#include "Graph.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm> // Include this header for std::reverse

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
