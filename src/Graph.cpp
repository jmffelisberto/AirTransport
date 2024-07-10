#include "Graph.h"
#include "Airport.h"
#include "Airline.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

void Graph::addAirport(const std::string &code) {
    if (adjList.find(code) == adjList.end()) {
        adjList[code] = std::vector<std::pair<std::string, std::string>>();
    }
}

void Graph::addFlight(const std::string &source, const std::string &target, const std::string &airline) {
    adjList[source].emplace_back(target, airline);
}

std::vector<std::string> Graph::getShortestPath(const std::string &start, const std::string &end, const std::unordered_set<std::string> &airlinePrefs) {
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
            if (airlinePrefs.empty() || airlinePrefs.find(flight.second) != airlinePrefs.end()) {
                if (visited.find(flight.first) == visited.end()) {
                    q.push(flight.first);
                    visited.insert(flight.first);
                    prev[flight.first] = airport;
                }
            }
        }
    }

    return {};
}

std::vector<std::string> Graph::getShortestPathAmongMultipleAirports(const std::vector<std::string> &source_airports, const std::vector<std::string> &target_airports, std::unordered_set<std::string> &airlinePrefs) {
    std::vector<std::string> shortestPath;
    int minPathLength = 99999999;

    for (const auto &source : source_airports) {
        for (const auto &target : target_airports) {
            std::vector<std::string> path = getShortestPath(source, target, airlinePrefs);
            if (!path.empty() && path.size() < minPathLength) {
                minPathLength = path.size();
                shortestPath = path;
            }
        }
    }

    return shortestPath;
}

std::vector<std::string> Graph::getCityAirports(const std::unordered_map<std::string, Airport>& airports, const std::string &city) {
    std::vector<std::string> cityAirports;
    for (const auto &entry : airports) {
        if (entry.second.city == city) {
            cityAirports.push_back(entry.first);
        }
    }
    return cityAirports;
}

void Graph::displayAirportNetwork(const std::string &airport, const std::unordered_map<std::string, Airline> &airlines) {
    std::cout << std::endl << std::endl;
    if (adjList.find(airport) == adjList.end()) {
        std::cout << "Airport " << airport << " not found." << std::endl;
        return;
    }

    std::cout << "These are the Airlines operating in " << airport << ": \n" << std::endl;
    for (const auto &flight : adjList[airport]) {
        std::string airline = flight.second;
        Airline a = airlines.at(airline);
        std::cout << a.name << "(" << a.callsign << ") from " << a.country << " --> " << a.code << std::endl;
    }
    std::cout << std::endl;
}

void Graph::displayDeparturesInfo(const std::string &airport, const std::unordered_map<std::string, Airport> &airports) {
    std::unordered_set<std::string> presentAirlines, presentCities, presentCountries, presentAirports;
    Airport currAirport;
    std::cout << std::endl;
    std::cout << airport << " Departures: \n" << std::endl;
    for (const auto &flight : adjList[airport]) {
        if (flight.second != "" && presentAirlines.find(flight.second) == presentAirlines.end()) {
            presentAirlines.insert(flight.second);
        }
        if (flight.first != "" && presentAirports.find(flight.first) == presentAirports.end()) {
            presentAirports.insert(flight.first);
        }
        currAirport = airports.at(flight.first);
        if (currAirport.city != "" && presentCities.find(currAirport.city) == presentCities.end()) {
            presentCities.insert(currAirport.city);
        }
        if (currAirport.country != "" && presentCountries.find(currAirport.country) == presentCountries.end()) {
            presentCountries.insert(currAirport.country);
        }
    }
    std::cout << "Number of Departures: " << adjList[airport].size() << std::endl;
    std::cout << "Number of Cities Accessible through " << airport << ": " << presentCities.size() << std::endl;
    std::cout << "Number of Countries Accessible through " << airport << ": " << presentCountries.size() << std::endl;
    std::cout << "Number of Airlines Operating @ " << airport << ": " << presentAirlines.size() << std::endl << std::endl;
}

void Graph::dfsLimitedDepth(const std::string &airport, int depth, std::unordered_set<std::string> &visited, std::unordered_set<std::string> &presentAirports, std::unordered_set<std::string> &presentCities, std::unordered_set<std::string> &presentCountries, const std::unordered_map<std::string, Airport> &airports) {
    visited.insert(airport);

    if (depth <= 0) {
        return;
    }

    for (const auto &flight : adjList[airport]) {
        const std::string &destinationAirport = flight.first;
        const Airport &currAirport = airports.at(destinationAirport);
        if (visited.find(destinationAirport) == visited.end()) {
            if (presentCities.find(currAirport.city) == presentCities.end()) {
                presentCities.insert(currAirport.city);
            }
            if (presentCountries.find(currAirport.country) == presentCountries.end()) {
                presentCountries.insert(currAirport.country);
            }
            presentAirports.insert(destinationAirport);
            dfsLimitedDepth(destinationAirport, depth - 1, visited, presentAirports, presentCities, presentCountries, airports);
        }
    }
}

void Graph::displayAirportCoverage(const std::string &airport, int numFlights, const std::unordered_map<std::string, Airport> &airports) {
    std::unordered_set<std::string> presentCities, presentCountries, presentAirports, visited;
    Airport currAirport;
    std::cout << std::endl;
    std::cout << airport << " For a maximum of " << numFlights << ",\n" << "the " << airport << " reaches:\n" << std::endl;
    dfsLimitedDepth(airport, numFlights, visited, presentAirports, presentCities, presentCountries, airports);
    std::cout << "- " << presentAirports.size() << " airports;\n";
    std::cout << "- " << presentCities.size() << " cities;\n";
    std::cout << "- " << presentCountries.size() << " countries.\n" << std::endl;
}
