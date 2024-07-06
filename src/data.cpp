#include "data.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Data> readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Data> data;
    std::string line;

    if (file.is_open()) {
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string token;
            Data row;

            std::getline(ss, token, ',');
            row.date = token;

            std::getline(ss, token, ',');
            row.open = std::stod(token);

            std::getline(ss, token, ',');
            row.high = std::stod(token);

            std::getline(ss, token, ',');
            row.low = std::stod(token);

            std::getline(ss, token, ',');
            row.close = std::stod(token);

            std::getline(ss, token, ',');
            row.volume = std::stoi(token);

            data.push_back(row);
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }
    return data;
}
