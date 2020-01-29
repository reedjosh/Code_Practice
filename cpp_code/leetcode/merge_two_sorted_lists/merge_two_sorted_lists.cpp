#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;    
    ListNode(int x) : val(x), next(NULL) {} // Constructor.
    };


void addToList(ListNode* list, vector<int> nums){
    // Don't want to lose head, so use this pointer instead.
    ListNode* present = list; 

    // Traverse to the end of the list.
    while(present->next != NULL)
        present = present->next;

    // Create the new node and append it.
    for (auto it : nums){
        ListNode* new_node = new ListNode(it);
        present->next = new_node;
        present = present->next;
        }
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

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
            ListNode dummy(0);
            ListNode* conductor = &dummy;
    
            while(l1 && l2){ // While there are two lists.
                if (l1->val < l2->val){  // Pick the smaller number.
                    conductor->next = l1;
                    l1 = l1 ? l1->next : l1;
                    }
                else{
                    conductor->next = l2;
                    l2 = l2 ? l2->next : l2;
                    }
                conductor = conductor->next; // Set conductor to tail.
                }
    
            conductor->next = (l1) ? l1 : l2; // Connect conductor to remaining list.
            return dummy.next;
            }
    };


int main(){

    Solution solution;

    ListNode* l1 = new ListNode(1);
    
    //addToList(l1, {3});

    ListNode* l2 = new ListNode(-5);
    //addToList(l2, {6, 7});

    printList(l1);
    printList(l2);


    ListNode* result = solution.mergeTwoLists(l1, l2);

    printList(result);

    return 0;    
    }
