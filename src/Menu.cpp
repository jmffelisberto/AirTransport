#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <unordered_set>
#include "Menu.h"
#include "Graph.h"
#include "Airport.h"

void Menu::displayMainMenu(const std::vector<Airport> &airports, Graph &graph) {
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
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice1;
    switch (choice1) {
        case 1:
            displayBestFlightMenu(airports, graph);
            break;
        case 2:
            break;
        case 3:
            std::cout << "Exiting..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "Goodbye!" << std::endl;
            return;
        default:
            displayInvalidChoice(airports, graph);
            break;
    }
}

void Menu::displayBestFlightMenu(const std::vector<Airport> &airports, Graph &graph) {
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
            displayBestFlightByCityMenu(airports, graph);
            break;
        case 2:
            displayBestFlightByAirportMenu(airports, graph);
            break;
        default:
            displayInvalidChoice(airports, graph);
            break;
    }
}

std::unordered_set<std::string> Menu::getAirlinePreferences() {
    std::unordered_set<std::string> airlines;
    int choice;
    std::string airline;

    std::cout << "Do you want to specify preferred airlines? (1 for Yes, 0 for No): ";
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "Enter the airlines you prefer (enter DONE when finished):" << std::endl;
        while (true) {
            std::cin >> airline;
            if (airline == "DONE") break;
            airlines.insert(airline);
        }
    }
    return airlines;
}

void Menu::displayBestFlightByCityMenu(const std::vector<Airport> &airports, Graph &graph) {
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

    std::unordered_set<std::string> airlines = getAirlinePreferences();

    std::vector<std::string> result = graph.getShortestPathAmongMultipleAirports(source_airports, target_airports, airlines);

    std::cout << "Result size: " << result.size() << std::endl;

    if (!result.empty()) {
        std::cout << "Shortest path: ";
        for (const auto &airport : result) {
            std::cout << airport << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found between the specified cities." << std::endl;
    }
}

void Menu::displayBestFlightByAirportMenu(const std::vector<Airport> &airports, Graph &graph) {
    std::string airport1, airport2;
    std::cout << "Enter the airport you are departing from: ";
    std::cin >> airport1;
    std::cout << "Enter the airport you are going to: ";
    std::cin >> airport2;

    std::unordered_set<std::string> airlines = getAirlinePreferences();

    std::vector<std::string> result = graph.getShortestPath(airport1, airport2, airlines);

    std::cout << "Shortest path from " << airport1 << " to " << airport2 << ":\n";
    for (const auto &airport : result) {
        std::cout << airport << " ";
    }
    std::cout << std::endl;
}

void Menu::displayInvalidChoice(const std::vector<Airport> &airports, Graph &graph) {
    std::cout << "Invalid choice. Please try again." << std::endl;
    std::cout << "Redirecting..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int counter = 0; counter < 5; counter++) {
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    displayMainMenu(airports, graph);
}
