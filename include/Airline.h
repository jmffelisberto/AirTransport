#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

class Airline {
public:
    Airline() : code(""), name(""), callsign(""), country("") {}
    Airline(const std::string &code, const std::string &name, const std::string &callsign, const std::string &country);
    std::string code;
    std::string name;
    std::string callsign;
    std::string country;
};

#endif // AIRLINE_H

