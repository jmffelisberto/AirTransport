#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

class Airport {
public:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    double latitude;
    double longitude;

    Airport(const std::string &code, const std::string &name, const std::string &city, const std::string &country, double latitude, double longitude);
};

#endif // AIRPORT_H
