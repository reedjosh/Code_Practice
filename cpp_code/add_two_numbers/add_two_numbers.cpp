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

//int reverseListToNum(ListNode* l1){
//    // Don't want to lose head, so use this pointer instead.
//    ListNode* present = l1; 
//
//    int number = 0;
//    int tensPlace = 1;
//
//    // Traverse to the end of the list.
//    while(present->next != NULL){
//        number += present->val * tensPlace;
//        tensPlace *= 10;
//        present = present->next;
//        }
//    number += present->val * tensPlace;
//    return number;
//    }
//
//
//ListNode* numToReverseList(int num){
//    // For each node, parse the digit using mod and divide. 
//    // Then insert the digit into the list.
//    unsigned long tensPlace = 1; // Gets quite large and must be able to get larger than an integer.
//    int digit = 0;
//
//    digit = num/tensPlace % 10; // Parse first digit.
//    tensPlace *= 10;
//    ListNode* list = new ListNode(digit); // Create the list.
//    while (num >= tensPlace){ // Populate the list for each digit.
//        cout << "digit " << digit << endl;
//        cout << "tensPlace " << tensPlace << endl;
//        digit = num/tensPlace % 10;
//        tensPlace *= 10;
//        addToList(list, digit);
//        printList(list);
//        } 
//    return list;
//    }
//
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
//    // Adds two numbers origninally represented by linked lists.
//    // Returns a number as a linked list.
//    // The digits are reversed order.
//    int total = reverseListToNum(l1) + reverseListToNum(l2);
//    cout << "Total: " << total << endl;
//    return numToReverseList(total);
//    }

struct dAndc{
    int digit, carry;
    };
    

dAndc sumAndCarry(int v1, int v2, int carry){
    // Sums numbers and returns a digit with a carry.
    dAndc result;
    int sum = v1 + v2 + carry;
    result.digit = sum % 10;
    if (sum >= 10) result.carry = 1;
    else result.carry = 0;
    return result;
    }

ListNode* addLists(ListNode* l1, ListNode* l2){
    // Adds one list to another already created list.
    ListNode* l1_conductor = l1;
    ListNode* l2_conductor = l2;
    dAndc result = {0, 0}; // digit and carry struct

    // Sum over the elements in l1.
    while (l1_conductor->next != NULL){
        result = sumAndCarry(l1_conductor->val, l2_conductor->val, result.carry);
        l2_conductor->val = result.digit;
        if (l2_conductor->next == NULL) l2_conductor->next = new ListNode(0);
        l2_conductor = l2_conductor->next;
        l1_conductor = l1_conductor->next;
        }
   
    // Do a final suming with l1 and l2 
    result = sumAndCarry(l1_conductor->val, l2_conductor->val, result.carry);
    l2_conductor->val = result.digit;

    // Propogate any remaining carry. 
    while (result.carry == 1){
        if (l2_conductor->next == NULL) 
            l2_conductor->next = new ListNode(0);
        l2_conductor = l2_conductor->next;
        result = sumAndCarry(0, l2_conductor->val, result.carry);
        l2_conductor->val = result.digit;
        }
    return l2;
    }

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    // Adds two numbers origninally represented by linked lists.
    // Returns a number as a linked list.
    // The digits are reversed order.
    ListNode* l3 = new ListNode(0);

    l3 = addLists(l1, l3);
    l3 = addLists(l2, l3);

    return l3;
    }

int main(){

    dAndc dcresult = {0, 0};
    cout << "Test sum and carry..." << endl;

    dcresult = sumAndCarry(2, 9, dcresult.carry);
    cout << dcresult.carry << " <-carry digit-> " << dcresult.digit << endl;

    dcresult = sumAndCarry(1, 9, 0);
    cout << dcresult.carry << " <-carry digit-> " << dcresult.digit << endl;

    cout << "Test 1..." << endl;

    ListNode* l1 = new ListNode(2);
    addToList(l1, 4);
    addToList(l1, 3);

    ListNode* l2 = new ListNode(5);
    addToList(l2, 6);
    addToList(l2, 4);

    printList(l1);
    printList(l2);


    ListNode* result = addTwoNumbers(l1, l2);
    printList(result);

    cout << "Test 2..." << endl;

    
    l1 = new ListNode(3);
    addToList(l1, 6);
    addToList(l1, 2);
    addToList(l1, 1);
    addToList(l1, 3);
    addToList(l1, 4);
    addToList(l1, 9);
    addToList(l1, 3);
    addToList(l1, 5);
    addToList(l1, 1);

    l2 = new ListNode(0);
    addToList(l2, 6);
    addToList(l2, 9);
    addToList(l2, 9);
    addToList(l2, 1);
    addToList(l2, 4);
    addToList(l2, 4);
    addToList(l2, 0);
    addToList(l2, 5);

    printList(l1);
    printList(l2);

    result = addTwoNumbers(l1, l2);
    printList(result);

    cout << "Test 3" << endl;

    l1 = new ListNode(9);
    addToList(l1, 9);
    addToList(l1, 9);

    l2 = new ListNode(1);
    printList(l1);
    printList(l2);

    result = addTwoNumbers(l1, l2);
    printList(result);


    cout << "Test 4" << endl;

    l1 = new ListNode(0);
    l2 = new ListNode(1);

    printList(l1);
    printList(l2);

    result = addTwoNumbers(l1, l2);
    printList(result);
    
    return 0;    
    }
