#include <iostream>
#include "linked_list.hpp"

using namespace std;

int main () {

//Question 3
LinkedList nasdaqList;

//companies position and stock price March 14th 2025
nasdaqList.push_back(1, 235.11);  // Apple
nasdaqList.push_back(2, 379.78);  // Microsoft
nasdaqList.push_back(3, 118.61);  // NVIDIA
nasdaqList.push_back(4, 197.41);  // Amazon
nasdaqList.push_back(5, 165.32);  // GOOG
nasdaqList.push_back(6, 163.27);  // GOOGL
nasdaqList.push_back(7, 607.46);  // Meta
nasdaqList.push_back(8, 196.2);   // AVGO
nasdaqList.push_back(9, 891.81);  // Costco
nasdaqList.push_back(10, 901.46); // Netflix
nasdaqList.push_back(11, 707.68); // ASML
nasdaqList.push_back(12, 60.32);  // Cisco
nasdaqList.push_back(13, 76.87);  // AstraZeneca
nasdaqList.push_back(14, 454.56); // Linde
nasdaqList.push_back(15, 312.23); // Amgen

double totalCost = 0.0;
for (int i = 0; i < nasdaqList.size(); i++) {
    Node* company = nasdaqList.at(i);
    totalCost = totalCost + (3 * company->value);
}
cout << "Total cost of buying 3 shares of each company: $" << totalCost << endl;

return 0;
}

