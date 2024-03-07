#include "BinarySearchTree.h"

void clearBuffer();

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

	return 0;
}

void clearBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		continue;
}