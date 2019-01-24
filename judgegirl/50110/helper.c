#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(int val) {
	Node *ret = (Node*)malloc(sizeof(Node));
	ret->n = val;
	ret->left = ret->right = NULL;
	return ret;
}
Node *FlipTree(Node *root) {
	if ( root == NULL )
		return NULL;
	Node *ret = new_node(root->n);
	ret->left = FlipTree(root->right);
	ret->right = FlipTree(root->left);
	return ret;
}
int isIdentical(Node *tree1, Node *tree2) {
	if ( tree1 == NULL && tree2 == NULL )
		return 1;
	if ( tree1 == NULL || tree2 == NULL || tree1->n != tree2->n )
		return 0;
	return isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right);
}
void traverse(Node *root, int data[], int d) {
	if ( root->left == NULL && root->right == NULL ) {
		data[0] += d;
		data[1]++;
		return;
	}
	if ( root->left != NULL )
		traverse(root->left, data, d + 1);
	if ( root->right != NULL )
		traverse(root->right, data, d + 1);
}
void depthAvg(Node *root) {
	int data[2] = {0};
	traverse(root, data, 0);
	printf("%d/%d\n", data[0], data[1]);
}
