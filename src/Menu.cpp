#include <iostream>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include "Menu.h"
#include "Graph.h"
#include "Airport.h"

void Menu::displayMainMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines) {
    int choice1;
    std::cout << "   _   _    _____                               _    " << std::endl;
    std::cout << "  /_\\ (_)_ |_   _| _ __ _ _ _  ____ __  ___ _ _| |_ " << std::endl;
    std::cout << " / _ \\| | '_|| || '_/ _` | ' \\(_-< '_ \\/ _ \\ '_|  _|" << std::endl;
    std::cout << "/_/ \\_\\_|_|  |_||_| \\__,_|_||_/__/ .__/\\___/_|  \\__|" << std::endl;
    std::cout << "                                 |_|                " << std::endl;
    std::cout << "                                                    " << std::endl;
    std::cout << "Hello! Welcome to AirTransport. Please select an option:\n" << std::endl;
    std::cout << "1. Best flight for you" << std::endl;
    std::cout << "2. Airport Information" << std::endl;
    std::cout << "3. Exit\n" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice1;
    std::string airport;
    switch (choice1) {
        case 1:
            displayBestFlightMenu(airports, graph, airlines);
            break;
        case 2:
            std::cout << std::endl;
            std::cout << "Please, enter the airport you want further information from:\n" << std::endl;
            std::cout << "Enter the airport code: ";
            std::cin >> airport;
            displayAirportInfoMenu(airports, graph, airlines, airport);
            break;
        case 3:
            std::cout << "Exiting..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "Goodbye!" << std::endl;
            return;
        default:
            displayInvalidChoice(airports, graph, airlines);
            break;
    }
}

void Menu::displayAirportInfoMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines, const std::string& airport) {
    int choice17, numFlights;
    std::string airport2;

    std::cout << "Airport selected: " << airport << std::endl;
    std::cout << "Now, please select the option that best represents what you want to know about the airport:\n" << std::endl;
    std::cout << "1. Airport ID (name, city, country...)" << std::endl;
    std::cout << "2. Airport Airway Network" << std::endl;
    std::cout << "3. Airport Departures Info" << std::endl;
    std::cout << "4. Airport Coverage" << std::endl;
    std::cout << "5. Return to Main Menu\n" << std::endl;
    std::cout << "Your choice: ";
    
    std::string input;
    std::cin >> input;

    // Validate if the input is a number
    try {
        choice17 = std::stoi(input);
    } catch (std::invalid_argument const &e) {
        std::cout << "Invalid choice. Please enter a number from 1 to 5." << std::endl;
        std::cout << "Redirecting..." << std::endl;
        for (int counter = 0; counter < 5; counter++) {
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        displayAirportInfoMenu(airports, graph, airlines, airport);
        return;
    } catch (std::out_of_range const &e) {
        std::cout << "Invalid choice. Please enter a number from 1 to 5." << std::endl;
        std::cout << "Redirecting..." << std::endl;
        for (int counter = 0; counter < 5; counter++) {
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        displayAirportInfoMenu(airports, graph, airlines, airport);
        return;
    }

    if (choice17 < 1 || choice17 > 5) {
        std::cout << "Invalid choice. Please enter a number from 1 to 5." << std::endl;
        std::cout << "Redirecting..." << std::endl;
        for (int counter = 0; counter < 5; counter++) {
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        displayAirportInfoMenu(airports, graph, airlines, airport);
        return;
    }

    switch (choice17) {
        case 1:
            displayAirportID(airports, graph, airport, airlines);
            displayAirportInfoMenu(airports, graph, airlines, airport);
            break;
        case 2:
            graph.displayAirportNetwork(airport, airlines);
            displayAirportInfoMenu(airports, graph, airlines, airport);
            break;
        case 3:
            graph.displayDeparturesInfo(airport, airports);
            displayAirportInfoMenu(airports, graph, airlines, airport);
            break;
        case 4:
            std::cout << std::endl;
            std::cout << "Enter the number of flights (depth) you want to consider: ";
            std::cin >> numFlights;
            graph.displayAirportCoverage(airport, numFlights, airports);
            displayAirportInfoMenu(airports, graph, airlines, airport);
            break;
        case 5:
            displayMainMenu(airports, graph, airlines);
            break;
        default:
            // This case should never be reached due to previous checks
            break;
    }
}

void Menu::displayBestFlightMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines) {
    int choice2;
    std::cout << std::endl;
    std::cout << "Let's find you our best flight!" << std::endl;
    std::cout << "Please, first select if you want to search by city or airport:\n" << std::endl;
    std::cout << "1. I want to search by cities." << std::endl;
    std::cout << "2. I want to select a specific airport.\n" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice2;
    switch (choice2) {
        case 1:
            displayBestFlightByCityMenu(airports, graph, airlines);
            displayMainMenu(airports, graph, airlines);
            break;
        case 2:
            displayBestFlightByAirportMenu(airports, graph, airlines);
            displayMainMenu(airports, graph, airlines);
            break;
        default:
            displayInvalidChoice(airports, graph, airlines);
            break;
    }
}

std::unordered_set<std::string> Menu::getAirlinePreferences() {
    std::unordered_set<std::string> userAirlines;
    int choice;
    std::string airline;

    std::cout << "Do you want to specify preferred airlines? (1 for Yes, 0 for No): ";
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "Enter the airlines you prefer (enter DONE when finished):" << std::endl;
        while (true) {
            std::cin >> airline;
            if (airline == "DONE") break;
            userAirlines.insert(airline);
        }
    }
    return userAirlines;
}

void Menu::displayBestFlightByCityMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines) {
    std::string city1, city2;
    std::cout << "Enter the city you are departing from: ";
    std::cin >> city1;
    std::cout << "Enter the city you are going to: ";
    std::cin >> city2;
    std::cout << "\n";

    std::vector<std::string> source_airports = graph.getCityAirports(airports, city1);
    std::vector<std::string> target_airports = graph.getCityAirports(airports, city2);

    std::cout << "Source Airports: ";
    for (const auto &airport : source_airports) {
        std::cout << airport << " ";
    }
    std::cout << std::endl;

    std::cout << "Target Airports: ";
    for (const auto &airport : target_airports) {
        std::cout << airport << " ";
    }
    std::cout << std::endl;

    std::unordered_set<std::string> airlinePrefs = getAirlinePreferences();

    std::vector<std::string> result = graph.getShortestPathAmongMultipleAirports(source_airports, target_airports, airlinePrefs);

    std::cout << "\nResult size: " << result.size() << std::endl;

    if (!result.empty()) {
        std::cout << "Shortest path: ";
        for (const auto &airport : result) {
            std::cout << airport << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found between the specified cities.\n" << std::endl;
    }
}

void Menu::displayBestFlightByAirportMenu(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines) {
    std::string airport1, airport2;
    std::cout << "Enter the airport you are departing from: ";
    std::cin >> airport1;
    std::cout << "Enter the airport you are going to: ";
    std::cin >> airport2;

    std::unordered_set<std::string> airlinePrefs = getAirlinePreferences();

    std::vector<std::string> result = graph.getShortestPath(airport1, airport2, airlinePrefs);

    if (!result.empty()) {
        std::cout << "\nShortest path from " << airport1 << " to " << airport2 << ":\n";
        for (const auto &airport : result) {
            std::cout << airport << " ";
        }
    } else std::cout << "No path found between the specified airports.";
    std::cout << std::endl << std::endl;
}

void Menu::displayAirportID(const std::unordered_map<std::string, Airport>& airports, Graph &graph, const std::string& airport, std::unordered_map<std::string, Airline> &airlines) {
    if (airports.find(airport) != airports.end()) {
        const Airport& a = airports.at(airport);
        std::cout << "Name: " << a.name << std::endl; 
        std::cout << "Located in " << a.city << ", " << a.country << std::endl;
        std::cout << "Coordinates @ " << a.latitude << ", " << a.longitude << std::endl;
        std::cout << std::endl;
        std::cout << "Press \"Esc\" and then \"Enter\" to go back to the previous menu." << std::endl;
        while (true) {
            if (std::cin.get() == 27) {
                displayAirportInfoMenu(airports, graph, airlines, airport);
            }
        }
    } else {
        std::cout << "Airport code not found." << std::endl;
        std::cout << "Press \"Esc\" and then \"Enter\" to go back to the previous menu." << std::endl;
        while (true) {
            if (std::cin.get() == 27) {
                displayAirportInfoMenu(airports, graph, airlines, airport);
            }
        }
    }
}

void Menu::displayInvalidChoice(const std::unordered_map<std::string, Airport>& airports, Graph &graph, std::unordered_map<std::string, Airline> &airlines) {
    std::cout << "Invalid choice. Please try again." << std::endl;
    std::cout << "Redirecting..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int counter = 0; counter < 5; counter++) {
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    displayMainMenu(airports, graph, airlines);
}