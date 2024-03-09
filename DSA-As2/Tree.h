#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#pragma once 

#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
//#include "time.h"

typedef struct TreeNode* link;
struct TreeNode {
    link pLeft;
    char data;
    link pRight;
};

void clearBuffer();

link initTree();

link insert(link root, char data);

link newNode(char data);

void searchTree(link root);

link search(link root, char data);

int countNodes(link root);

int getTreeHeight(link root);

void traversePreOrder(link root);
void traverseInOrder(link root);
void traversePostOrder(link root);

void traverseReverseOrder(link root);

void freeTree(link root);

#endif //BINARYTREE_TREE_H
