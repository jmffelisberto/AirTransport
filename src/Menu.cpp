#include <iostream>
#include <chrono>
#include <thread>
#include "Menu.h"

void Menu::displayMainMenu() {
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
        displayBestFlightMenu();
        break;

    case 2:
        break;

    case 3:
        std::cout << "Exiting..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Goodbye!" << std::endl;
        return;
    
    default:
        displayInvalidChoice();
        break;
    }
}

void Menu::displayBestFlightMenu() {
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
        displayBestFlightByCityMenu();
        break;
    
    case 2:
        displayBestFlightByAirportMenu();
        break;

    default:
        displayInvalidChoice();
        break;
    }
}

void Menu::displayBestFlightByCityMenu(){
    std::string city1, city2;
    std::cout << "Enter the city you are departing from: ";
    std::cin >> city1;
    std::cout << "Enter the city you are going to: ";
    std::cin >> city2;
    //TODO: Implement the search by city
    std::cout << "Work in Progress..." << std::endl;
}

void Menu::displayBestFlightByAirportMenu(){
    std::string airport1, airport2;
    std::cout << "Enter the airport you are departing from: ";
    std::cin >> airport1;
    std::cout << "Enter the airport you are going to: ";
    std::cin >> airport2;
    //TODO: Implement the search by airport
    std::cout << "Work in Progress..." << std::endl;
}

void Menu::displayInvalidChoice(){
    std::cout << "Invalid choice. Please try again." << std::endl;
    std::cout << "Redirecting..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int counter = 0; counter < 5; counter++){
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    displayMainMenu();
}
   
