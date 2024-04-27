#include "PasswordManager.h"
#include <iostream>  // For std::cout
#include <ctime>     // For time-based seeding in the future if needed
#include <random>    // For std::random_device and std::mt19937
#include <algorithm> // For std::shuffle, if you decide to use it later

// Constructor implementation (empty since we aren't initializing anything special)
PasswordManager::PasswordManager() {}

// Destructor implementation (empty since there's no dynamic memory to free)
PasswordManager::~PasswordManager() {}

// Attempts to add a password to the map. Returns true if the site didn't exist and was added.
bool PasswordManager::addPassword(const std::string& site, const std::string& password) {
    auto result = passwords.insert({ site, password });
    return result.second;  // 'second' is true if the insert was successful.
}

// Tries to remove a password. Returns true if the site existed and the password was removed.
bool PasswordManager::removePassword(const std::string& site) {
    return passwords.erase(site) > 0;  // erase returns the number of elements removed.
}

// Retrieves the password for a given site, returns an empty string if the site doesn't exist.
std::string PasswordManager::getPassword(const std::string& site) const {
    auto it = passwords.find(site);  // Try to find the site.
    if (it != passwords.end()) {     // If found...
        return it->second;           // return the password.
    }
    return "";  // If not found, return an empty string.
}

// Outputs all site-password pairs to the console.
void PasswordManager::listAll() const {
    for (const auto& pair : passwords) {  // Range-based for loop to go through all pairs.
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Generates a random password of the requested length...The length can be changed
std::string PasswordManager::generatePassword(size_t length) {
    const std::string chars =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!@#$%^&*()";  // Characters to use in the password.

    std::random_device rd;  // will work on both windows and unix,linux systems
    std::mt19937 generator(rd());  // The Mersenne Twister generator, more random than rand(). this just does 32 bit, I didnt do the 64, prime numbers 
    // one less then than the ^2 mnot really random cause it's  determinde with a seed from random_device seemed like the most used one and fastest
    //I found while tyring to research
    std::uniform_int_distribution<> distribution(0, chars.size() - 1);  // Uniform distribution for index

    std::string password;  // Start with an empty password.

    // Build a password of the requested length
    for (size_t i = 0; i < length; ++i) {
        password += chars[distribution(generator)];  // Append a random character from chars
    }

    return password;  // Return the generated password.
}
