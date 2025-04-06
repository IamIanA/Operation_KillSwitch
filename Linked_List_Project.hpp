#ifndef Linked_List_Project_H
#define Linked_List_Project_H


class ListNode {
    public:
        int id;
        double data;
        ListNode* next;
        ~ListNode();
        ListNode (int new_id, double new_data);

};

//hi
//hiya

class LinkedList {
    private:
    ListNode* head;

    public:
    ~LinkedList();
    LinkedList();

    ListNode* get_head();
    void push_front(int id, double data); // Adds a node to the front of the list
    void push_back(int id, double data);  // Adds a node to the back of the list
    void insert(int id, double data, int index); // Inserts a node at a specific index
    double search(int id); // Searches for a node by key and returns its value

    ListNode* at(int index); // Returns the node at a specific index
    int size();
    bool remove(int index);
    bool remove_id(int id);
    bool remove_data(double data);


    void print();
    void selection_sort();
    void bubble_sort();

};


#endif 