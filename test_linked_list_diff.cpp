#include "linked_list.hpp"
#include <iostream>

bool test_push_back();
bool test_push_front();
bool test_is_empty();
bool test_size();

int main() {
	std::cout << "Test Push Back: " << (test_push_back() ? "Passed" : "Failed") << std::endl;
	std::cout << "Test Push Front: " << (test_push_front() ? "Passed" : "Failed") << std::endl;	
	std::cout << "Test Is Empty: " << (test_is_empty() ? "Passed" : "Failed" ) << std::endl;
	std::cout << "Test Size: " << (test_size() ? "Passed" : "Failed") << std::endl; 
}

bool test_size(){
	LinkedList l1,l2,l3;
	l2.push_front(10);
	l3.push_front(30);
	l3.push_front(40);
	l3.push_front(50);

	int rv1 = l1.size();
	int rv2 = l2.size();
	int rv3 = l3.size();

	bool av1 = rv1 == 0;
	bool av2 = rv2 == 1;
    bool av3 = rv3 == 3;

	return av1 && av2 && av3;
}	



bool test_is_empty() {
	LinkedList l1, l2;
	l2.push_front(10);
	
	bool rv1 = l1.is_empty();
	bool rv2 = l2.is_empty();

	bool av1 = rv1 && !rv2;
	
	return av1;
}


bool test_push_front() {
	LinkedList l;

	bool rv1 = l.push_front(30); // this is the empty case
	bool rv2 = l.push_front(20);
	bool rv3 = l.push_front(10);

	Node* l_head = l.get_head();
	bool av1 = rv1 && l_head->value == 10;
	bool av2 = rv2 && l_head->next->value == 20;
	bool av3 = rv3 && l_head->next->next->value == 30 && l_head->next->next->next == nullptr;

	return av1 && av2 && av3;
}

bool test_push_back() {
	// set up
	LinkedList l;

	//execution
	bool rv1 = l.push_back(10);
	bool rv2 = l.push_back(20);
	bool rv3 = l.push_back(30);

	// validation
	Node* l_head = l.get_head();

	// 10 -> 20 -> 30
	bool av1 = rv1 && l_head->value == 10;
	bool av2 = rv2 && l_head->next->value == 20;
	bool av3 = rv3 && l_head->next->next->value == 30 && l_head->next->next->next == nullptr;

	//clean up
	return av1 && av2 && av3;
}	

//if the list does not have an index that matches, return false. if the index is 0, add the node with th egiven value to the front of the listm otherwise, traverse to the given index, and add the node to that position, pushing further nodes one back