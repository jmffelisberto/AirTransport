#include "Airport.h"
#include <vector>
#include <iostream>

Airport::Airport(const std::string &code, const std::string &name, const std::string &city, const std::string &country, double latitude, double longitude)
    : code(code), name(name), city(city), country(country), latitude(latitude), longitude(longitude) {}
