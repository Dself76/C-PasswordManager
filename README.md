# C-PasswordManager
A beginner-friendly C++ project featuring a password manager that can store, retrieve, and generate passwords for various websites. Implements fundamental C++ concepts and standard library containers.
# Password Manager in C++

## Introduction
This is one of my initial C++ projects, a simple yet effective password manager. It is designed to help users manage their website credentials by storing, retrieving, and generating secure passwords.

## Features
- **Add Password**: Safely store passwords keyed by website names.
- **Remove Password**: Remove passwords from the storage.
- **Retrieve Password**: Quickly retrieve passwords using the website name.
- **List All**: Display all stored website-password pairs.
- **Generate Password**: Create a strong, random password of specified length.

## How It Works
The `PasswordManager` class uses an `std::unordered_map` to store website-password pairs. It offers a user-friendly command-line interface to interact with the password manager's features. Password generation uses a robust random number generator to ensure password strength.

## Getting Started
To run the password manager:
1. Clone the repository.
2. Open the solution file `PasswordManager.sln` in Visual Studio.
3. Build and run the project.

## Usage
- Upon launch, the program prompts users to add a new password or generate a random one.
- The user can input website details and choose to enter a custom password or generate a random one.
- Passwords can be listed or removed as needed.

## Contributions
As one of my earliest projects, it serves as a learning tool, and contributions for improvement are welcome. Feel free to fork the project, open issues, and submit pull requests.

## License
This project is open-sourced under the MIT license. See the [LICENSE](LICENSE.md) file for details.

## Acknowledgements
- Special thanks to my educators for guiding me through my learning journey in C++.
- Appreciation for the open-source community for providing the resources that helped in building this project.
