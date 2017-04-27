#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;    
    ListNode(int x) : val(x), next(NULL) {}
    };


void addToList(ListNode* list, int val){
    // Don't want to lose head, so use this pointer instead.
    ListNode* present = list; 

    // Traverse to the end of the list.
    while(present->next != NULL)
        present = present->next;

    // Create the new node and append it.
    ListNode* new_node = new ListNode(val);
    present->next = new_node;
    }


void printList(ListNode* list){
    // Print the value in each node.
    // Don't want to lose head, so use this pointer instead.
    ListNode* present = list; 
   
    // Iterate over nodes until the end.
    while(present->next != NULL){
        cout << present->val << "->";
        present = present->next;
        }
    cout << present->val << endl;
    }

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* 

        While(l1 || l2){
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;

            if (l1->val <= l2->val) 
            else 
            }
    }


int main(){


    ListNode* l1 = new ListNode(2);
    addToList(l1, 4);
    addToList(l1, 3);

    ListNode* l2 = new ListNode(5);
    addToList(l2, 6);
    addToList(l2, 4);

    printList(l1);
    printList(l2);


    ListNode* result = mergeTwoLists(l1, l2);

    printList(result);

    return 0;    
    }
