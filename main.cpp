#include "PasswordManager.h"
#include <iostream>
#include <limits>

int main() {
    PasswordManager manager;
    char choice;

    std::cout << "Do you want to add a new password? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        std::string site;
        std::string password;

        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter the site name: ";
        std::getline(std::cin, site);

        std::cout << "Do you want to generate a random password? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            // Generate a random password of a given length, e.g., 12 characters
            password = manager.generatePassword(12);
            std::cout << "Generated password: " << password << std::endl;
        }
        else {
            // Clear input buffer if not generating password
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter the password: ";
            std::getline(std::cin, password);
        }

        if (manager.addPassword(site, password)) {
            std::cout << "Password added successfully!" << std::endl;
            std::cout << "Password saved." << std::endl;
        }
        else {
            std::cout << "Failed to add password. That site may already exist." << std::endl;
        }
    }
    else {
        std::cout << "No password added." << std::endl;
    }

    // Optional: List all passwords after adding
    // manager.listAll();

    return 0;
}
