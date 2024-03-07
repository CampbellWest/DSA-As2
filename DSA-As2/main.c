#include "BinarySearchTree.h"

int main() {

	srand(time(NULL));

	int num = rand() % (20 - 11 + 1) + 11;

	link root = initTree();

	for (int i = 0; i < num; i++) {
		if (i == 0) {
			root = insert(root, (rand() % (122 - 97 + 1) + 97));
			continue;
		}
		insert(root, (rand() % (122 - 97 + 1) + 97));
	}

	printf("\n\n");
	traversePreOrder(root);
	printf("\n\n");
	traverseInOrder(root);
	printf("\n\n");
	traversePostOrder(root);
	printf("\n\n");

	char c;

	do {
		c = getc(stdin);
		clearBuffer();

		if (search(root, c) == NULL) 
			printf("not in tree\n");
		else
			printf("found in tree\n");

	} while (isalpha(c));

	printf("\n\n");

	printf("%i total nodes\n\n", countNodes(root));

	printf("%i tallest path\n\n", getTreeHeight(root));

	return 0;
}