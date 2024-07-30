#include <iostream>
#include <map>
#include <string>
#include <sstream>

// Function to convert a string to a double
static double ft_stod(const std::string& str) {
    double num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

void findClosestDate(const std::map<std::string, double>& bitcoin_data, const std::string& transaction_date) {
    std::map<std::string, double>::const_iterator it = bitcoin_data.lower_bound(transaction_date);

    if (it != bitcoin_data.end() && it->first == transaction_date) {
        // Exact match found
        std::cout << "Exact match found for date: " << transaction_date << " with value: " << it->second << std::endl;
    } else {
        // If lower_bound doesn't find an exact match
        if (it == bitcoin_data.begin()) {
            // No earlier date available
            std::cout << "No earlier date found for transaction date: " << transaction_date << std::endl;
        } else {
            // Move back one element to get the closest previous date
            --it;
            std::cout << "Closest earlier date found for transaction date: " << transaction_date 
                      << " is: " << it->first << " with value: " << it->second << std::endl;
        }
    }
}

int main() {
    std::map<std::string, double> bitcoin_data;
    bitcoin_data["2024-07-01"] = 50000.0;
    bitcoin_data["2024-07-10"] = 52000.0;
    bitcoin_data["2024-07-15"] = 53000.0;

    std::string transaction_date = "2024-07-10";

    findClosestDate(bitcoin_data, transaction_date);

    return 0;
}