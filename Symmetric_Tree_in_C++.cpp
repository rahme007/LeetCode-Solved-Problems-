
#include <iostream>
#include<deque>


using namespace std;

// this is breadth first search (BFS) solution
// deque is used in First in First Out (FIFO) system
typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, TreeNode* left, TreeNode* right) {
        val = x;
        this->left = left;
        this->right = right;
    }

}TreeNode;

class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (!root->left && !root->right)
                return true;
            else if (!root->left && root->right)
                return false;
            else if (root->left && !root->right)
                return false;

            // dividing the tree into two subtree
            deque<TreeNode*> qleft{root->left};  // initializing left subtree
            deque<TreeNode*> qright{root->right}; // initializing right subtree
            TreeNode* centerNodeLeft;
            TreeNode* centerNodeRight;

            while (!qleft.empty() && !qright.empty()) {
                centerNodeLeft = qleft.front(); // storing the first element 
                centerNodeRight = qright.front();
                qleft.pop_front(); // deleting front node for left queue
                qright.pop_front(); // deleting front node for right queue    


                if (centerNodeLeft==nullptr && centerNodeRight==nullptr)
                    continue;


                if (centerNodeLeft == nullptr || centerNodeRight == nullptr ||  centerNodeLeft->val != centerNodeRight->val)
                    return false;

                qleft.push_back(centerNodeLeft->left); // populating left subtree with left node
                qright.push_back(centerNodeRight->right); // populating right subtree with right node
                qright.push_back(centerNodeRight->left);
                qleft.push_back(centerNodeLeft->right);

            }

            return true;

            }
        

};

int main()
{
    TreeNode* tn = new TreeNode(1, nullptr, nullptr);
    tn->left = new TreeNode(2, nullptr, nullptr);
    tn->right = new TreeNode(2, nullptr, nullptr);
    tn->left->right = new TreeNode(3, nullptr, nullptr);
    tn->right->right = new TreeNode(3, nullptr, nullptr);
  /*  TreeNode* tn = new TreeNode(1, nullptr, nullptr);
    tn->left = new TreeNode(2, nullptr, nullptr);
    tn->right = new TreeNode(2, nullptr, nullptr);
    tn->left->left = new TreeNode(3, nullptr, nullptr);
    tn->left->right = new TreeNode(4, nullptr, nullptr);
    tn->right->left = new TreeNode(4, nullptr, nullptr);
    tn->right->right = new TreeNode(3, nullptr, nullptr);*/
    Solution s;
    bool isSym = s.isSymmetric(tn);
    cout << isSym << endl;

    return 0;
}

// On LeetCode :
// Runtime : 4 ms, faster than 48.61 % of C++ online submissions for Symmetric Tree.
// Memory Usage : 17 MB, less than 6.18 % of C++ online submissions for Symmetric Tree.
