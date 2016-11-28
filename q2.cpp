#include <iostream>
#include <vector>
using namespace std;

// Struct to contain next and value.
struct node {
    int val;
    node *next;
    };

// Linked list class. 
// Support for integers only.
// Can add values to tail and print.
class LinkedList {
    node *head;
    public:
        //LinkedList();
        void Add(int a);
        void Print();
    };

// Add a new value to tail of LinkedList.
void LinkedList::Add(int a) {

    // Create new node.
    node *new_node = new node;  // allocate
    new_node->val = a;  // set val

    // Place new node.
    if (head == NULL)  // place directly after head
        head = new_node;
    else {  // place at end of list
        node *location = head;
        while (location->next != NULL)
            location = location->next;
        location->next = new_node;
        }
    }

// Print LinkedList in the form: 1->2->3->4
void LinkedList::Print() {

    // Don't manipulate head pointer.
    node *location = head;
    
    // Print value and move to next node per loop.
    while (location->next != NULL) {
        cout << location->val << "<-";  // print val<-
        location = location->next;
        }
        // Print final value.
        cout << location->val <<endl;  // print val\n
    }

// Test Harness
main() {   
    LinkedList *myList = new LinkedList();
    myList->Add(1);
    myList->Add(2);
    myList->Add(3);
    myList->Print();
    myList->Add(4);
    myList->Print();
    myList->Add(5);
    myList->Add(6);
    myList->Print();
    return 0;
    }
