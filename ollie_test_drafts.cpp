
#include "Linked_List_Project.hpp"
#include <iostream>

bool test_remove_data();
bool test_selection_sort();
bool test_bubble_sort();

int main() {
    std::cout << "test_remove_data " << (test_remove_data() ? "Passed!" : "Failed") << std::endl;
    std::cout << "test_selection_sort " << (test_selection_sort() ? "Passed!" : "Failed") << std::endl;
    std::cout << "test_bubble_sort " << (test_bubble_sort() ? "Passed!" : "Failed") << std::endl;
}

bool test_remove_data() {
    //set up
    LinkedList l;
    l.push_back(0, 10);
    l.push_back(1, 20);
    l.push_back(2, 30);
    l.push_back(3, 40);

    //execution
    Node* l_head = l.get_head();

    bool rv1 = l.remove_data(30);
    bool rv2 = l_head->next->next =! nullptr;

    //validation
    bool av1 = rv1 && rv2 && l_head->next->next->value == 40;

    return av1;
}


bool test_selection_sort() {
    //set up
    LinkedList l;
    l.push_back(2);
    l.push_back(4);
    l.push_back(1);
    l.push_back(3);

    //execution
    bool rv1 = l.selection_sort;
    bool av1 = rv1;

    //validation
    std::cout << "Selection sort" << std::endl;
    l.print();

    return av1;
}

bool test_bubble_sort() {
    //set up
    LinkedList l;
    l.push_back(2);
    l.push_back(4);
    l.push_back(1);
    l.push_back(3);

    //execution
    bool rv1 = l.bubble_sort;
    bool av1 = rv1;

    //validation
    std::cout << "Bubble sort:" << std::endl;
    l.print();

    return av1;
}

///////////////////////////////////////////////////////////

int main {
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

    int min = years.at(0);
    int max = years.at(0);
    int temp;

    for (node* iter = head, iter->next != nullptr, iter->next) {          //use != nullptr or .size?
        temp = iter->next->value;
        temp = temp * 10000;

        if (temp < min) {
            min = temp;
        }

        else if (temp > min) {
            max = temp;
        }
    }

    int diff = max - min;

    std::cout << "Smallest value: " << min << ", largest value: " << max << ", difference: " << diff << std::endl;s
        
    return 0;
}
