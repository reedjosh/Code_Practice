#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };


class Solution{
public:
    int findTilt(TreeNode* root){
        int tilt = 0;
        subSum(root, tilt); // Tracks tilt while summing tree recursively.
        return tilt;
        }
private:
    void toArr(TreeNode* subRoot, int& tilt){
        if (!subRoot) return; //  Base case.
        }
    };


        //cout << "subRoot: " << subRoot->val << " left: " << left << " right: " << right << " tilt: " << tilt << endl;

int main(void){
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    //   1
    //  / \
    // 2   3
    //  \
    //   5 
    //
    // Tilt should be 9

    int result = solution.findTilt(root);
    cout << "Tilt: " << result << endl;
    }
