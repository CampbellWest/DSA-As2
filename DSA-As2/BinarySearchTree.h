#pragma once

#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"

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

link search(link root, char data);

int countNodes(link root);

int getTreeHeight(link root);

void traversePreOrder(link root);
void traverseInOrder(link root);
void traversePostOrder(link root);