#include "Reader.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

std::unordered_map<std::string, Airport> Reader::readAirports(const std::string &filePath) {
    std::unordered_map<std::string, Airport> airports;
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
            airports[row[0]] = Airport(row[0], row[1], row[2], row[3], std::stod(row[4]), std::stod(row[5]));
        }
    }

    return airports;
}

std::unordered_map<std::string, Airline> Reader::readAirlines(const std::string &filePath) {
    std::unordered_map<std::string, Airline> airlines;
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
            airlines[row[0]] = Airline(row[0], row[1], row[2], row[3]);
        }
    }

    return airlines;
}

std::vector<Flight> Reader::readFlights(const std::string &filename, Graph &graph) {
    std::ifstream file(filename);
    std::string line;
    std::vector<Flight> flights;

    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string token;
        std::vector<std::string> row;

        while (std::getline(stream, token, ',')) {
            row.push_back(token);
        }

        if (row.size() >= 3) { // Ensure there are enough columns in the row
            std::string source = row[0];
            std::string target = row[1];
            std::string airline = row[2];
            graph.addFlight(source, target, airline);
            flights.push_back(Flight(source, target, airline));
        }
    }

    return flights;
}
