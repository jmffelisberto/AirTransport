#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

class Flight {
public:
    std::string source;
    std::string target;
    std::string airline;

    Flight(const std::string &source, const std::string &target, const std::string &airline);
};

#endif // FLIGHT_H
