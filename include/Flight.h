#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

class Flight {
public:
    Flight(const std::string &source, const std::string &target, const std::string &airline);

    std::string source;
    std::string target;
    std::string airline;
};

#endif // FLIGHT_H
