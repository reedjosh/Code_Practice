#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vec){
    cout << "[";
    for(auto i: vec)
        cout << ' ' << i;
    cout << "]" << endl;
    }

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i1 = m-1, i2 = n-1, iTot = n+m-1;
        while (i2 >= 0){
            if ((nums1[i1] > nums2[i2]) && (i1>=0))
                nums1[iTot--] = nums1[i1--];
            else
                nums1[iTot--] = nums2[i2--];
            }
        }
    };

int main(void){
    Solution solution;
    vector<int> in_vec_a, in_vec_b, out_vec;
    
    cout << "Test..." << endl;
    in_vec_a = {1, 2, 5, 0, 0, 0, 0};
    in_vec_b = {-4, -3, 2, 4};

    print(in_vec_a);
    print(in_vec_b);
    solution.merge(in_vec_a, 3, in_vec_b, 4);
    print(in_vec_a);


    cout << "Test..." << endl;
    in_vec_a = {1, 0, 0, 0, 0, 0};
    in_vec_b = {-4, -3, 1, 2, 4};

    print(in_vec_a);
    print(in_vec_b);
    solution.merge(in_vec_a, 1, in_vec_b, in_vec_b.size());
    print(in_vec_a);

    cout << "Test..." << endl;
    in_vec_a = {0, 0, 0, 0};
    in_vec_b = {-3, 1, 2, 4};

    print(in_vec_a);
    print(in_vec_b);
    solution.merge(in_vec_a, 0, in_vec_b, 4);
    print(in_vec_a);

    in_vec_a = {0, 0, 0, 0};
    in_vec_b = {-3, 1, 2, 4};

    print(in_vec_a);
    print(in_vec_b);
    solution.merge(in_vec_a, 0, in_vec_b, 4);
    print(in_vec_a);
    }
