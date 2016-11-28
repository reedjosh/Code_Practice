#include <iostream>
#include <vector>
using namespace std;

void set(int **matrix, int size) {
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            matrix[i][j] = i+j;
            }
        }
    }

void print(int **matrix, int size) {
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            cout << matrix[i][j] << " ";
            }
        cout << endl;
        }
    }

// in place swap four elements
void cyclic_roll(int &a, int &b, int &c, int &d) {
    int temp = a;
    a = b;
    b = c;
    c = d;
    d = temp;
    }

void cyclic_roll2(int &a, int &b, int &c, int &d) {
    int temp = d;
    d = c;
    c = b;
    b = a;
    a = temp;
    }

// rotate matrix in place 4 elements from 
// each side at a time
void rotate90(int **matrix, int size) {
    for(int i=0; i<size/2; i++)
       for(int j=0; j<(size+1)/2; j++)
           cyclic_roll(matrix[i][j], matrix[size-1-j][i], matrix[size-1-i][size-1-j], matrix[j][size-1-i]);
    }

void rotate_neg90(int **matrix, int size) {
    for(int i=0; i<size/2; i++)
       for(int j=0; j<(size+1)/2; j++)
           cyclic_roll2(matrix[i][j], matrix[size-1-j][i], matrix[size-1-i][size-1-j], matrix[j][size-1-i]);
    }

main() {   
    int rows, cols = 4;
    int **matrix = new int*[rows];
    for (int i=0; i<rows; ++i)
        matrix[i] = new int[cols];
    set(matrix, 4);
    print(matrix, 4);
    cout << endl;
    rotate90(matrix, 4);
    print(matrix, 4);
    cout << endl;
    rotate_neg90(matrix, 4);
    rotate_neg90(matrix, 4);
    print(matrix, 4);
        return 0;
    }
