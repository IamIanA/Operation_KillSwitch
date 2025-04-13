#include <iostream>
#include <vector>
#include <iomanip>
#include "linked_list.hpp"

using namespace std;

int main () {

//Quesiton 1

LinkedList primeList;

    //The first 20 prime numbers
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

    // Populate the list with primes (id) and their inverses (data)
    for (int p : primes) {
        double inverse = 1.0 / p; //Calculate the inverse
        primeList.push_back(p, inverse);// Add to the list using your method
    }
    //Calculate the sum of the values (inverses) using a manual loop
    double sumOfInverses = 0.0;
    ListNode* current = primeList.get_head();// Get the head of the list
    while (current != nullptr) { // Iterate through the list
        sumOfInverses += current->data; // Add the data field (the inverse)
        current = current->next; // Move to the next node
    }

    // Output the sum
    cout << fixed << setprecision(10); //Set precision for output
    cout << "The sum of the multiplicative inverses of the first 20 prime numbers is: " << sumOfInverses << endl;


//Question 2

LinkedList years;
years.push_back(1,365.25);          //Julian
years.push_back(2, 365.24219);      //Revised
years.push_back(3, 365.2425);       //Gregorian
years.push_back(4, 365.25636);      //Siderial
years.push_back(5, 365.24219);      //Tropical
years.push_back(6, 365.259636);     //Anomalistic
years.push_back(7, 346.62);         //Eclipse
years.push_back(8, 411.78443029);   //Full moon
years.push_back(9, 365.2568983);    //Gaussian


years.selection_sort();

int min = years.at(1)->data * 10000;
int max = years.at(years.size)->data * 10000;

int diff = max - min;

std::cout << "Smallest value: " << min << ", largest value: " << max << ", difference: " << diff << std::endl;
        
return 0;

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

