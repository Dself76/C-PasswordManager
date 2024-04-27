#ifndef PASSWORDMANAGER_H  // Guard to prevent multiple inclusions
#define PASSWORDMANAGER_H

#include <random>  // For random number generation
#include <algorithm>  // For std::shuffle

#include <string>  // String type used for passwords
#include <unordered_map>  // Hash table for storing passwords

// Class to manage passwords for various sites.
class PasswordManager {

private:
    // Hash table to store site-password pairs. the password and site
    std::unordered_map<std::string, std::string> passwords;

public:
    // Constructor
    PasswordManager();
    // Destructor
    ~PasswordManager();

    // Adds a password for a given site. Returns true if added successfully.
    bool addPassword(const std::string& site, const std::string& password);

    // Removes a password for a given site. Returns true if removed successfully.
    bool removePassword(const std::string& site);

    // Retrieves a password for a given site, returns empty if not found.
    std::string getPassword(const std::string& site) const;

    // Prints out all site-password pairs to the console.
    void listAll() const;

    // Generates a random password of a specified length. The length can be changed later
    std::string generatePassword(size_t length);
};

#endif // it should work
