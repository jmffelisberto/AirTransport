#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <vector>
#include <iostream>

class Airport {
public:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    double latitude;
    double longitude;

    Airport(const std::string &code, const std::string &name, const std::string &city, const std::string &country, double latitude, double longitude);
    std::vector<std::string> getCityAirports(const std::vector<Airport> &airports, const std::string &city);
};

#endif // AIRPORT_H
