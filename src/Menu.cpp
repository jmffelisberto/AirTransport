#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "Menu.h"
#include "Graph.h"
#include "Airport.h"

void Menu::displayMainMenu(std::vector<Airport> airports) {
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
    switch (choice1)
    {
    case 1:
        displayBestFlightMenu(airports);
        break;

    case 2:
        break;

    case 3:
        std::cout << "Exiting..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Goodbye!" << std::endl;
        return;
    
    default:
        displayInvalidChoice(airports);
        break;
    }
}

void Menu::displayBestFlightMenu(std::vector<Airport> airports) {
    int choice2;
    std::cout << std::endl;
    std::cout << "Let's find you our bebst flight!" << std::endl; 
    std::cout << "Please, first select if you want to search by city or airport:\n" << std::endl;
    std::cout << "1. I want to search by cities." << std::endl;
    std::cout << "2. I want to select a specific airport.\n" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice2;
    switch (choice2)
    {
    case 1:
        displayBestFlightByCityMenu(airports);
        break;
    
    case 2:
        displayBestFlightByAirportMenu(airports);
        break;

    default:
        displayInvalidChoice(airports);
        break;
    }
}

void Menu::displayBestFlightByCityMenu(std::vector<Airport> airports){
    std::string city1, city2;
    std::cout << "Enter the city you are departing from: ";
    std::cin >> city1;
    std::cout << "Enter the city you are going to: ";
    std::cin >> city2;
    std::cout << "\n";
    Graph graph;
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
    /* std::vector<std::string> result = graph.getShortestPathAmongMultipleAirports(source_airports, target_airports);
    std::cout << result.size() << std::endl;
    std::cout << "Shortest path from " << city1 << " to " << city2 << ":\n";
    for (const auto &airport : result) {
        std::cout << airport << " ";
    } */
}

void Menu::displayBestFlightByAirportMenu(std::vector<Airport> airports){
    std::string airport1, airport2;
    std::cout << "Enter the airport you are departing from: ";
    std::cin >> airport1;
    std::cout << "Enter the airport you are going to: ";
    std::cin >> airport2;
    //TODO: Implement the search by airport
    std::cout << "Work in Progress..." << std::endl;
}

void Menu::displayInvalidChoice(std::vector<Airport> airports){
    std::cout << "Invalid choice. Please try again." << std::endl;
    std::cout << "Redirecting..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int counter = 0; counter < 5; counter++){
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    displayMainMenu(airports);
}
   
