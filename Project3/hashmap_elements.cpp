#include "hashmap_elements.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
std::unordered_map<std::string, double> hashmap;
std::unordered_map<std::string, int> elements_numbers;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

void create_hashmap() {
    std::ifstream file("elements.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open elements.csv" << std::endl;
        return;
    }

    std::string first_line;
    if (!std::getline(file, first_line)) {
        std::cerr << "Failed to read first line of elements.csv" << std::endl;
        file.close();
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string column1, column2, column3, column4;
        if (std::getline(iss, column1, ',') && std::getline(iss, column2, ',') && std::getline(iss, column3, ',') && std::getline(iss, column4, ',')) {
            try {
                hashmap[column3] = std::stod(column4);
            }
            catch (const std::exception& e) {
                std::cerr << "Failed to parse mass value for element " << column3 << ": " << e.what() << std::endl;
            }
        }
        else {
            std::cerr << "Failed to parse line in elements.csv: " << line << std::endl;
        }
    }
    file.close();
}
double return_mass() {
    double mass = 0;
    for (const auto& pair : elements_numbers) {
        const std::string& key = pair.first;
        int value = pair.second;
        if (hashmap[key] != 0) {
            mass += hashmap[key] * value;
        }
        else {
            return 0;
        }


    }
    return mass;

}
bool is_space(unsigned char c) {
    return std::isspace(c);
};
void create_elements_hashmap(const std::string& equation) {
    elements_numbers.clear();
    int i = 0;
    while (i < equation.size()) {
        if (isupper(equation[i]) && i + 1 < equation.size() && islower(equation[i + 1])) {
            std::string element = equation.substr(i, 2);
            i += 2;
            int count = 0;
            while (i < equation.size() && isdigit(equation[i])) {
                count = count * 10 + (equation[i] - '0');
                i++;
            }
            if (count == 0) {
                count = 1;
            }
            elements_numbers[element] += count;
        }
        else if (isupper(equation[i])) {
            std::string element = std::string(1, equation[i]);
            i++;
            int count = 0;
            while (i < equation.size() && isdigit(equation[i])) {
                count = count * 10 + (equation[i] - '0');
                i++;
            }
            if (count == 0) {
                count = 1;
            }
            elements_numbers[element] += count;
        }
        else if (equation[i] == '(') {
            int n = 1;
            while (i + n < equation.size() && equation[i + n] != ')') {
                n++;
            }
            int multiply = 1; 
            if (i + n + 1 < equation.size() && isdigit(equation[i + n + 1])) {
                multiply = equation[i + n + 1] - '0';
            }
            i++;
            if (isupper(equation[i]) && i + 1 < equation.size() && islower(equation[i + 1])) {
                std::string element = equation.substr(i, 2);
                i += 2;
                int count = 0;
                while (i < equation.size() && isdigit(equation[i])) {
                    count = count * 10 + (equation[i] - '0');
                    i++;
                }
                if (count == 0) {
                    count = 1;
                }
                elements_numbers[element] += count * multiply;
            }
            else if (isupper(equation[i])) {
                std::string element = std::string(1, equation[i]);
                i++;
                int count = 0;
                while (i < equation.size() && isdigit(equation[i])) {
                    count = count * 10 + (equation[i] - '0');
                    i++;
                }
                if (count == 0) {
                    count = 1;
                }
                elements_numbers[element] += count * multiply;
            }
            else {
                i++;
            }
        }
        else {
            i++;
        }
    }
};
std::string reduceProportions() {
    std::vector<int> proportions;
    for (const auto& pair : elements_numbers) {
        int value = pair.second;
        proportions.push_back(value);

    }

    int gcd1 = std::accumulate(proportions.begin(), proportions.end(), proportions[0], gcd);
    std::vector<int> reduced_proportions(proportions.size());
    std::transform(proportions.begin(), proportions.end(), reduced_proportions.begin(), [gcd1](int n) {return n / gcd1;});
    std::string result = "";
    int i = 0;
    for (const auto& pair : elements_numbers) {
        const std::string& key = pair.first;
        result += key + ":" + std::to_string(reduced_proportions[i]) + " ";
        i++;
    }
    return result;
};
