#include "Tree.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        continue;
}

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

    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return search(root->pRight, data);

    return search(root->pLeft, data);
}

int countNodes(link root) {

    if (root == NULL)
        return 0;

    return (countNodes(root->pLeft) + countNodes(root->pRight) + 1);
}

int getTreeHeight(link root) {

    int leftHeight, rightHeight;

    if (root == NULL)
        return -1;

    leftHeight = getTreeHeight(root->pLeft);
    rightHeight = getTreeHeight(root->pRight);

    if (leftHeight > rightHeight)
        return (leftHeight + 1);
    else
        return (rightHeight + 1);
}

void traversePreOrder(link root) {
    if (root == NULL)
        return;

    printf("%c->", root->data);
    traversePreOrder(root->pLeft);
    traversePreOrder(root->pRight);
}

void traverseInOrder(link root) {
    if (root == NULL)
        return;

    traverseInOrder(root->pLeft);
    printf("%c->", root->data);
    traverseInOrder(root->pRight);
}

void traversePostOrder(link root) {
    if (root == NULL)
        return;

    traversePostOrder(root->pLeft);
    traversePostOrder(root->pRight);
    printf("%c->", root->data);
}

void traverseReverseOrder(link root){
    if (root == NULL)
        return;

    traverseReverseOrder(root->pRight);
    printf("%c->", root->data);
    traverseReverseOrder(root->pLeft);
}

void freeTree(link root){
    if(root == NULL)
        return;

    freeTree(root->pRight);
    freeTree(root->pLeft);
    printf("%c freed\n", root->data);
    free(root);
}