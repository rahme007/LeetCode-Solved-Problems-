// https://github.com/rahme007
//Range_Sum_of_BST_938: the problem is approach by DFS using recursion.
//Runtime:  53 ms (beats 98.48% of users with C)

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

}TreeNode;

TreeNode* create_node(int x) {
	TreeNode* t = (TreeNode*)calloc(1, sizeof(TreeNode));
	if (t) {
		t->val = x;
		t->left = NULL;
		t->right = NULL;
	}

	return t;
}

int rangeSumBST(struct TreeNode* root, int low, int high) {

	if (!root)
		return 0;
	else {
		int num = 0;
		if (root->val >= low && root->val <= high) {
			num = root->val; // storing the value following the condition
		}
		
		return num + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high); // summing the value under range interval
	}
}

int main() {
	// testing binary search tree
	TreeNode* tn = create_node(10);
	tn->left = create_node(5);
	tn->right = create_node(15);
	tn->left->left = create_node(3);
	tn->left->right = create_node(7);
	tn->right->right = create_node(18);

	int low = 7, high = 15;

	int sum = rangeSumBST(tn, low, high);

	// the sum should be 32
	printf("The range sum of BST: %d\n", sum);

	return 0;
}