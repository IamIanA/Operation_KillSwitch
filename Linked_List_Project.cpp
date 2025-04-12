#include "Linked_List_Project.hpp"
#include <iostream>


ListNode:: ListNode (int new_id, double new_data) {
    id = new_id;
    data = new_data;
    next = nullptr;
}

ListNode:: ~ListNode() {
    if (next != nullptr) {
        delete next;
        next = nullptr;
    }
};
 

LinkedList:: LinkedList() {
    head = nullptr;
}

LinkedList:: ~LinkedList() {
    if (head != nullptr) {
        delete head;
        head = nullptr;
    }
}

ListNode* LinkedList:: get_head() {
    return head;
}

void LinkedList:: push_back(int id, double data) {
    if (head == nullptr) {
        head = new ListNode(id, data);
    } else {
        ListNode* iter;
		for (iter = head; iter->next != nullptr; iter = iter->next);
        iter->next = new ListNode (id, data);
    }


}

void LinkedList:: push_front(int id, double data) {
    if (head == nullptr) {
        head = new ListNode(id , data);
    } else {
        ListNode* iter = new ListNode(id, data);
        iter -> next = head; 
        head = iter;
    }
}

void LinkedList:: insert(int id, double data, int index) {
    if (index = 0) {
        push_front(id , data);
        return;
    } 

    ListNode* new_node = new ListNode(id, data);
    ListNode* iter = head;
    for (int i = 1; i < index && iter != nullptr; i++) {
        iter = iter -> next; 
    }

    if (iter = nullptr) {
        std:: cerr << "You're out of bounds. \n";
        delete new_node;
        return;
    }

    new_node -> next = iter -> next;
    iter -> next = new_node;
}

double LinkedList:: search(int id) {
    for (ListNode* iter = head; iter != nullptr; iter = iter -> next) {
        if (iter -> id == id) {
            return iter -> data;
        }
    } 
    return -1.0; //return -1.0 if ID isn't found
}

ListNode* LinkedList:: at(int index) {
    ListNode* iter = head; 
    for (int i = 0; i < index && iter != nullptr; i++) {
        iter = iter -> next; 
    }
    return iter;
}

int LinkedList:: size() {
    int count = 0;
    ListNode* iter = head;
    while (iter != nullptr) {
        count ++;
        iter = iter -> next;
    }
    return count;
}

bool LinkedList:: remove(int index) {
    if (head == nullptr || index < 0) {
        return false;
    }

    if (index == 0) {
        ListNode* temp = head;
        head = head -> next;
        temp -> next = nullptr;
        delete temp;
        return true;
    }

    ListNode* iter = head; 
    for (int i = 1; i < index && iter -> next != nullptr; i++) {
        iter = iter -> next;
    }

    if (iter->next == nullptr) {
        return false;
    }

    ListNode* temp = iter -> next;
    iter -> next = temp -> next;
    temp -> next = nullptr;
    return true;
}

bool LinkedList:: remove_id(int id) {
    if (head == nullptr) {
        return false;
    }

    if (head -> id = id) {
        ListNode* temp = head;
        head = head -> next;
        temp -> next = nullptr; 
        delete temp;
        return true;
    }

    ListNode* iter = head;
    while (iter -> next != nullptr) {
        if (iter -> next -> id == id) {
            ListNode* temp = iter->next;
            iter->next = temp->next;
            temp->next = nullptr;
            delete temp;
            return true;
        }
        iter = iter -> next;
    }
    return false;
}

bool LinkedList:: remove_data(double data) {
    if (head == nullptr) {
        return false;
    }

    if (head -> data = data) {
        ListNode* temp = head;
        head = head -> next;
        temp -> next = nullptr; 
        delete temp;
        return true;
    }

    ListNode* iter = head;
    while (iter -> next != nullptr) {
        if (iter -> next -> data == data) {
            ListNode* temp = iter->next;
            iter->next = temp->next;
            temp->next = nullptr;
            delete temp;
            return true;
        }
        iter = iter -> next;
    }
    
    return false;
}

void LinkedList:: print() {
    if (head == nullptr) {
        std:: cout << "The List is empty." << std:: endl;
        return;
    }

    std:: cout << "Linked List Contents:" << std:: endl;
    std:: cout << "______________________" << std:: endl;

    ListNode* iter = head;
    while (iter != nullptr) {
        std:: cout << "ID: " << iter -> id << std:: endl;
        std:: cout << "Value " << iter -> data << std:: endl;

        iter = iter -> next;
    }
    std:: cout << "______________________" << std:: endl;
    std::cout << "Total items in Linked List: " << size() << std::endl;
    
}

void LinkedList:: selection_sort() {
    if (head == nullptr || head -> next == nullptr) {
        return;
    }

    for (ListNode* current = head; current != nullptr; current = current -> next) {
        ListNode* min_node = current;

        for (ListNode* runner = current -> next; runner != nullptr; runner = runner -> next) {
            if (runner -> id < min_node-> id) { 
                min_node = runner;
            }
        }

        if (min_node != current) {
            int temp_id = current -> id;
            current -> id = min_node -> id;
            min_node -> id = temp_id;

            double temp_data = current -> data;
            current -> data = min_node -> data;
            min_node -> data = temp_data;
        }



    }


}

void LinkedList:: bubble_sort() {
    if (head == nullptr || head -> next == nullptr) {
        return;
    }

    bool swapped;
    ListNode* end = nullptr;

    do {
        swapped = false;
        ListNode* current = head;

        while (current -> next != end) {
            if (current -> id > current -> next -> id) {
                int temp_id = current->id;
                current->id = current->next->id;
                current->next->id = temp_id;

                int temp_data = current->data;
                current->data = current->next->data;
                current->next->data = temp_data;

                swapped = true;

            }
            current = current -> next;
        }

        end = current;
        
    } while (swapped);
}

