/* Assignment 1 PHYS30672
Calculate transition energies from Bohr model
Theo Broxton 09/06/24 */

#include <iostream>
#include <limits>  // For std::numeric_limits
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

// Constants
const double EV_TO_JOULES = 1.60218e-19;  // Conversion factor from eV to Joules

// Function to get valid integer input
int getIntInput(const std::string& prompt) {
    std::string input;
    int value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if ((ss >> value) && !(ss >> input) && value > 0) {
            // Successfully extracted an integer and no remaining input, value is positive
            return value;
        } else {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        }
    }
}

// Function to get valid unit input (eV or J)
char getUnitInput(const std::string& prompt) {
    char unit;
    while (true) {
        std::cout << prompt;
        std::cin >> unit;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
        if (unit == 'e' || unit == 'E' || unit == 'j' || unit == 'J') {
            return unit;
        } else {
            std::cout << "Invalid input. Please enter 'e' for eV or 'j' for Joules." << std::endl;
        }
    }
}

// Function to get yes/no input for repeating the program
char getYesNoInput(const std::string& prompt) {
    char response;
    while (true) {
        std::cout << prompt;
        std::cin >> response;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
        if (response == 'y' || response == 'Y' || response == 'n' || response == 'N') {
            return response;
        } else {
            std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << std::endl;
        }
    }
}

// Function to calculate the energy transition
double calculateEnergy(int Z, int nj, int ni) {
    return 13.6 * std::pow(Z, 2) * (1.0 / std::pow(nj, 2) - 1.0 / std::pow(ni, 2));
}

// Function to convert eV to Joules
double convertEvToJoules(double energyEv) {
    return energyEv * EV_TO_JOULES;
}

int main() {
    char repeat;
    do {
        int Z = getIntInput("Enter the atomic number: ");
        int nj = getIntInput("Enter the initial principal quantum number: ");
        int ni = getIntInput("Enter the final principal quantum number: ");

        // Ensure final principal quantum number is lower than initial
        while (nj <= ni) {
            std::cout << "Final principal quantum number must be lower than the initial principal quantum number." << std::endl;
            nj = getIntInput("Enter the initial principal quantum number: ");
            ni = getIntInput("Enter the final principal quantum number: ");
        }

        double Eij = calculateEnergy(Z, nj, ni);
        // Energy of the emitted photon
        double photonEnergy = -Eij;

        char unit = getUnitInput("Enter the desired output unit (e for eV, j for Joules): ");

        // Set precision to 3 decimal places
        if (unit == 'j' || unit == 'J') {
            photonEnergy = convertEvToJoules(photonEnergy); // Convert eV to Joules
            std::cout << std::scientific << std::setprecision(3);
            std::cout << "The energy of the emitted photon is: " << photonEnergy << " J" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(3);
            std::cout << "The energy of the emitted photon is: " << photonEnergy << " eV" << std::endl;
        }

        repeat = getYesNoInput("Would you like to perform another calculation? (y/n): ");
    } while (repeat == 'y' || repeat == 'Y');

    std::cout << "Program terminated." << std::endl;

    return 0;
}