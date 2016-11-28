#include <iostream>
#include <vector>
using namespace std;

/* prints Fizz if divisible by 3
 * Buzz if 5
 * a if neither
 * then endline */

main()
{   
    // 1-100
    for (int a = 1; a < 101; a++){
        // could be better structured...
        if ((a % 3) == 0) { cout << "Fizz"; }
        if ((a % 5) == 0) { cout << "Buzz"; }
        if (((a % 3) != 0) && ((a % 5) != 0)) { cout << a; }
        cout << endl;
        }
    return 0;
}
