#include "Reader.h"
#include <fstream>
#include <sstream>

std::vector<Airport> Reader::readAirports(const std::string &filePath) {
    std::vector<Airport> airports;
    std::ifstream file(filePath);
    std::string line, word;

    if (file.is_open()) {
        std::getline(file, line); // Skip header
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::vector<std::string> row;
            while (std::getline(ss, word, ',')) {
                row.push_back(word);
            }
            airports.emplace_back(row[0], row[1], row[2], row[3], std::stod(row[4]), std::stod(row[5]));
        }
    }

    return airports;
}

std::vector<Airline> Reader::readAirlines(const std::string &filePath) {
    std::vector<Airline> airlines;
    std::ifstream file(filePath);
    std::string line, word;

    if (file.is_open()) {
        std::getline(file, line); // Skip header
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::vector<std::string> row;
            while (std::getline(ss, word, ',')) {
                row.push_back(word);
            }
            airlines.emplace_back(row[0], row[1], row[2], row[3]);
        }
    }

    return airlines;
}

std::vector<Flight> Reader::readFlights(const std::string &filePath, Graph &graph) {
    std::vector<Flight> flights;
    std::ifstream file(filePath);
    std::string line, word;

    if (file.is_open()) {
        std::getline(file, line); // Skip header
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::vector<std::string> row;
            while (std::getline(ss, word, ',')) {
                row.push_back(word);
            }
            flights.emplace_back(row[0], row[1], row[2]);
            graph.addFlight(row[0], row[1]);
        }
    }

    return flights;
}
