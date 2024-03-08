#include "Tree.h"

int main() {

    srand(time(NULL));

    int num = rand() % (20 - 11 + 1) + 11;

    link root = initTree();

    printf("Inserted Order\n");

    for (int i = 0; i < num; i++) {
        if (i == 0) {
            root = insert(root, (rand() % (122 - 97 + 1) + 97));
            continue;
        }
        insert(root, (rand() % (122 - 97 + 1) + 97));
    }

    printf("\n\nPreOrder\n");
    traversePreOrder(root);
    printf("\n\nInOrder\n");
    traverseInOrder(root);
    printf("\n\nPostOrder\n");
    traversePostOrder(root);
    printf("\n\nReversed InOrder\n");
    traverseReverseOrder(root);
    printf("\n\n");

    char c;

    do {
        if(!isalpha(c = getc(stdin)))
            break;

        clearBuffer();

        if (search(root, c) == NULL)
            printf("not in tree\n");
        else
            printf("found in tree\n");

    } while (1);

    printf("\n");

    printf("%i total nodes\n\n", countNodes(root));

    printf("%i tallest path\n\n", getTreeHeight(root));

    freeTree(root);

    return 0;
}