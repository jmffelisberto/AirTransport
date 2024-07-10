#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <vector>
#include <iostream>

class Airport {
public:
    Airport() : code(""), name(""), city(""), country(""), latitude(0.0), longitude(0.0) {}
    Airport(const std::string &code, const std::string &name, const std::string &city, const std::string &country, double latitude, double longitude);
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    double latitude;
    double longitude;
};

#endif // AIRPORT_H
