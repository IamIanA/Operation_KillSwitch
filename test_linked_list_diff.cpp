#include "Linked_List_Project.hpp"
#include <iostream>

bool test_push_back();
bool test_push_front();
bool test_size();
bool test_search();
bool test_insert();
bool test_at();
bool test_remove();
bool test_remove_id();
bool test_remove_data();

int main() {
	std:: cout << "Test Push Back: " << (test_push_back() ? "Passed" : "Failed") << std:: endl;
	std:: cout << "Test Push Front: " << (test_push_front() ? "Passed" : "Failed") << std:: endl;	
	std:: cout << "Test Size: " << (test_size() ? "Passed" : "Failed") << std:: endl; 
	std:: cout << "Test search function: " << ( test_search() ? "Passed" : "Failed" ) << std:: endl;
	std:: cout << "Test insert function: " << ( test_insert() ? "Passed" : "Failed" ) << std:: endl;
	std:: cout << "Test at function: " << ( test_at() ? "Passed" : "Failed" ) << std:: endl;
	std:: cout << "Test remove function: " << ( test_remove() ? "Passed" : "Failed" ) << std:: endl;
	std:: cout << "Test remove id function: " << ( test_remove_id() ? "Passed" : "Failed" ) << std:: endl;
	std:: cout << "Test remove data function: " << ( test_remove_data() ? "Passed" : "Failed" ) << std:: endl;
	
}

bool test_size(){
	LinkedList l1,l2,l3;

	bool rv1 = l1.size() == 0;

	l2.push_front(1, 30.0);
	l2.push_front(1, 20.0);
	l2.push_front(2, 50.0);
	bool rv2 = l2.size() == 3;

	l3.push_front(1, 10.0);
    l3.push_front(2, 20.0);
    bool rv3 = l3.size() == 2;

	return rv1 && rv2 && rv3;

}
	
bool test_push_front() {
	LinkedList l;
	l.push_front(1, 30.0);
	l.push_front(2, 20.0);
	l.push_front(3, 10.0);

	ListNode* l_head = l.get_head();
	bool av1 = l_head -> data == 10.0;
	bool av2 = l_head -> next -> data == 20.0;
	bool av3 = l_head -> next -> next -> data == 30.0;

	return av1 && av2 && av3;

}

bool test_push_back() {
	//set up
	LinkedList l;
	l.push_back(1, 10.0);
	l.push_back(2, 20.0);
	l.push_back(3, 30.0);
	
	ListNode* l_head = l.get_head();
	bool av1 = l_head -> data == 10.0;
	bool av2 = l_head -> next -> data == 20.0;
	bool av3 = l_head -> next -> next -> data == 30.0;

	return av1 && av2 && av3;

}	

bool test_search() {
	LinkedList l;
	l.push_front(1, 30.0);	
	l.push_front(2, 40.0);	
	l.push_front(3, 50.0);	

	bool case1 = l.search(2) == 40.0;
	bool case2 = l.search(1) == 30.0;
	bool case3 = l.search(4) == -1.0;

	return case1 && case2 && case3;

}

bool test_insert() {
	LinkedList l;
	
	l.insert(1, 10.0, 0);
	bool case1 = l.get_head() != nullptr && l.get_head() -> data == 10.0 && l.get_head() -> id == 1;

	l.insert(2, 20.0, 0);
	ListNode* secNode = l.get_head() -> next;
	bool case2 = l.get_head() != nullptr && l.get_head() -> data == 20.0 && l.get_head() -> id == 2;

	
	return case1 && case2;
}

bool test_at() {
	LinkedList l;
	l.push_back(1, 10.0); 
    l.push_back(2, 20.0); 
    l.push_back(3, 30.0); 

	ListNode* node_0 = l.at(0);
	bool case1 = node_0 != nullptr && node_0 -> id == 1 && node_0 -> data == 10.0;

	ListNode* node_1 = l.at(1);
	bool case2 = node_1 != nullptr && node_1 -> id == 2 && node_1 -> data == 20.0;

	ListNode* node_2 = l.at(2);
	bool case3 = node_2 != nullptr && node_2 -> id == 3 && node_2 -> data == 30.0;

	ListNode* node_3 = l.at(3);
	bool case4 = node_3 == nullptr;

	return case1 && case2 && case3 && case4;
}

bool test_remove() {
	LinkedList l;
	l.push_back(1, 10.0);
	l.push_back(2, 20.0);
	l.push_back(3, 30.0);

	bool case1 = l.remove(0) && l.get_head() -> id == 2 && l.get_head() -> data == 20.0;
	bool case2 = l.remove(1) && l.get_head() -> next == nullptr;
	bool case3 = !l.remove(5);
	bool case4 = l.remove(0) && l.get_head() == nullptr;

	return case1 && case2 && case3 && case4;
}

bool test_remove_id() {
	LinkedList l;
	l.push_back(1, 10.0);
	l.push_back(2, 20.0);
	l.push_back(3, 30.0);

	bool case1 = l.remove_id(2);
	bool validate1 = l.get_head() -> id == 1 && l.get_head() -> next -> id == 3;

	bool case2 = l.remove_id(1);
	bool validate2 = l.get_head() -> id == 3 && l.get_head() -> next == nullptr;

	bool case3 = !l.remove_id(5);
	
	bool case4 = l.remove_id(3);
	bool validate4 = l.get_head() == nullptr;

	return case1 && validate1 && case2 && validate2 && case3 && case4 && validate4; 

}

bool test_remove_data() {
	LinkedList l;
	l.push_back(1, 10.0);
	l.push_back(2, 20.0);
	l.push_back(3, 30.0);

	bool case1 = l.remove_data(20.0);
	bool validate1 = l.get_head() -> data == 10.0 && l.get_head() -> next -> data == 30.0;

	bool case2 = l.remove_data(10.0);
	bool validate2 = l.get_head() -> data == 30.0 && l.get_head() -> next == nullptr;

	bool case3 = !l.remove_data(50.0);
	
	bool case4 = l.remove_data(30.0);
	bool validate4 = l.get_head() == nullptr;

	return case1 && validate1 && case2 && validate2 && case3 && case4 && validate4; 

}