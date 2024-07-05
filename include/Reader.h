#ifndef READER_H
#define READER_H

#include <vector>
#include <string>
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"
#include "Graph.h"

class Reader {
public:
    static std::vector<Airport> readAirports(const std::string &filePath);
    static std::vector<Airline> readAirlines(const std::string &filePath);
    static std::vector<Flight> readFlights(const std::string &filePath, Graph &graph);
};

#endif // READER_H
