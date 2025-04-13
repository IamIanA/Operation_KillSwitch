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

class LinkedList {
    private:
    ListNode* head;



   public:
    ~LinkedList(); // Destructor to clean up the linked list
    LinkedList(); // Constructor to initialize the linked list

    ListNode* get_head(); // Returns the head node of the list

    void push_front(int id, double data); // Adds a node with given id and data to the front of the list
    void push_back(int id, double data); // Adds a node with given id and data to the back of the list
    void insert(int id, double data, int index); // Inserts a node with given id and data at a specific index
    double search(int id); // Searches for a node by id and returns its associated data value

    ListNode* at(int index); // Returns a pointer to the node located at a specific index
    int size(); // Returns the total number of nodes in the list
    bool remove(int index); // Removes the node at the specified index and returns true if successful
    bool remove_id(int id); // Removes the node with the specified id and returns true if successful
    bool remove_data(double data); // Removes the node with the specified data value and returns true if successful
    bool remove_data_fake(double data);

    void print(); // Prints all the nodes in the linked list

    void selection_sort(); // Sorts the linked list using the selection sort algorithm
    void bubble_sort(); // Sorts the linked list using the bubble sort algorithm
};


#endif 