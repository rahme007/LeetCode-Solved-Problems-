// https://github.com/rahme007
// the idea is to use DFS and find the max height and then
// determine the diameter in bottom up approach
// run time: 3 ms
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX(X, Y) ( (X>Y) ? (X) : (Y) )

typedef struct TreeNode {

	int val;
	struct TreeNode* left;
	struct TreeNode* right;

}TreeNode;

// int max(int a, int b) {
// 	return (a>b) ? a : b;
// }

struct TreeNode* create_node(int x) {
	struct TreeNode* t = calloc(1, sizeof(TreeNode));
	if (t) {
		t->val = x;
		t->left = NULL;
		t->right = NULL;
	}
	return t;
}

int heightOfBinaryTree(struct TreeNode* root, int* maxD) {
	if (!root)
		return -1;
	else {
		int hLeft = heightOfBinaryTree(root->left, maxD);
		int hRight = heightOfBinaryTree(root->right, maxD);
		maxD[0] = MAX(maxD[0], hLeft + hRight + 2);
		return 1 + MAX(hLeft , hRight);
	}
}


int diameterOfBinaryTree(struct TreeNode* root) {
	
	int* maxD = (int*)calloc(1, sizeof(int));
	if (maxD)
		maxD[0] = 0;
	int h = heightOfBinaryTree(root, maxD);
	if (maxD)
		return maxD[0];
	else
		return -1;
}

int main() {

	TreeNode* bt = create_node(1);
	bt->left = create_node(3);
	bt->left->left = create_node(7);
	bt->left->left->left = create_node(8);
	bt->left->left->left->left = create_node(9);
	bt->right = create_node(2);
	bt->left->right = create_node(4);
	bt->left->right->right = create_node(5);
	bt->left->right->right->right = create_node(6);

	int diameter = diameterOfBinaryTree(bt);

	printf("the diameter is: %d", diameter);
	printf("\n");

	return 0;
}