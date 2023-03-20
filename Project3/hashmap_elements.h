#ifndef HASHMAP_ELEMENTS_H
#define HASHMAP_ELEMENTS_H

#include <unordered_map>
#include <string>
#include <cctype>

extern std::unordered_map<std::string, double> hashmap;
extern std::unordered_map<std::string, int> elements_numbers;
int gcd(int a, int b);
void create_hashmap();
double return_mass();
bool is_space(unsigned char c);
void create_elements_hashmap(const std::string& equation);
std::string reduceProportions();
bool containsOnlyDigits(System::String^ string);
#endif