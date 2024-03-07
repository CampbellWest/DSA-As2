#include "BinarySearchTree.h"

link initTree() {
	link temp = (link)malloc(sizeof(struct TreeNode));
	return (temp = NULL);
}

link insert(link root, char data) {

	if (root == NULL) {
		printf("%c->", data);
		return newNode(data);
	}
		
	if (data < root->data)
		root->pLeft = insert(root->pLeft, data);
	else if (data > root->data)
		root->pRight = insert(root->pRight, data);

	return root;
}

link newNode(char data) {

	link temp = (link)malloc(sizeof(struct TreeNode));

	temp->data = data;
	temp->pLeft = temp->pRight = NULL;

	return temp;
}

link search(link root, char data) {

	if (root == NULL || root->data ==data)
		return root;

	if (root->data < data)
		return search(root->pRight, data);
	
	return search(root->pLeft, data);
}

int countNodes(link root) {
	return 0;
}

int determineTreeHeight(link root) {
	return 0;
}

void traversePreOrder(link root) {
	if (root == NULL)
		return;

	printf("%c->", root->data);
	traversePreOrder(root->pLeft);
	traversePreOrder(root->pRight);
	return;
}

void traverseInOrder(link root) {
	if (root == NULL)
		return;

	traverseInOrder(root->pLeft);
	printf("%c->", root->data);
	traverseInOrder(root->pRight);
	return;
}

void traversePostOrder(link root) {
	if (root == NULL)
		return;

	traversePostOrder(root->pLeft);
	traversePostOrder(root->pRight);
	printf("%c->", root->data);
	return;
}