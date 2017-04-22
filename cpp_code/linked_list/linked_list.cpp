#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;    
    };

class LinkedList{
    public:
        node *head;
        LinkedList();
        void add(int new_val);  
        void print(void);
    };

LinkedList::LinkedList(){
    head = NULL;
    }

void LinkedList::add(int new_val){
    // Create a new node for insertion.
    node *new_node = new node;
    new_node->val = new_val;
    new_node->next = NULL;

    if (head == NULL) { // Initiate head if not previously done.
        head = new_node;
        }
    else{ // Traverse to tail and add new_node there.
        // Can't change head, so use curr to traverse the list.
        node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        // Point current to new node.
        curr->next = new_node;
        }
    }

void LinkedList::print(void){

    if (head != NULL){ // If the list is not empty print elements in the list.

        // Since head can't be changed, use curr to traverse the list.
        node *curr = head;

        // Traverse and pring value with '->' symbol each time.
        while (curr->next != NULL){
            cout << curr->val << "->";
            curr = curr->next;
            }

        // Print the final value, and end the line.
        cout << curr->val << endl;
        }
    }

int main(){
    cout << "Making List...\n";
    LinkedList LL;

    cout << "Printing empty list...\n";
    LL.print();

    cout << "Adding first element...\n";
    LL.add(5);

    cout << "Adding second element...\n";
    LL.add(6);

    cout << "Printing list with two elements...\n";

    cout << "Adding third element...\n";
    LL.add(7);
    LL.print();

    return 0;    
    }
