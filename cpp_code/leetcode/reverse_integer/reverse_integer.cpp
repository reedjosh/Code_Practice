// Joshua Reed
// Practice Problem
// Spring, 2017
//
// Reverse the digits of an integer.
//
//      Example 1: x =  123, return  321
//      Example 2: x = -123, return -321
//
//      Also, the function should return 0 when the reversed integer overflows.

#include <iostream>
#include <climits>

using namespace std;

int reverse(int x){
    long reversed = 0; // Reversed is long to compare for integer overflow.
    int digit = 0;
    
    while(x){
        digit = x % 10; 
        reversed = reversed*10 + digit;
        x /= 10;
        }
    return (reversed == int(reversed)) ? reversed : 0;
    }

int main(void){
    cout << "-123 -> "  << reverse(-123) << endl;
    cout << " 123 ->  " <<  reverse(123) << endl;
    cout << INT_MIN << " ->  " <<  reverse(INT_MIN) << endl;
    cout << INT_MAX << " ->  " <<  reverse(INT_MAX) << endl;
    return 0;
    }

