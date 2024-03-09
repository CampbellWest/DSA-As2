#include "Tree.h"

int main() {

    srand(time(NULL));

    int num = rand() % (20 - 11 + 1) + 11;

    link root = initTree();

    printf("Inserted Order\n");

    for (int i = 0; i < num; i++){
        if (i == 0) {
            root = insert(root, (rand() % (122 - 97 + 1) + 97));
            continue;
        }
        insert(root, (rand() % (122 - 97 + 1) + 97));
    }

    printf("\n\nInOrder\n");
    traverseInOrder(root);

    printf("\n\n");
    //searchTree(root);  // search for specific char 

    printf("Total nodes: %i\n\n", countNodes(root));

    printf("Tallest path: %i\n\n", getTreeHeight(root));

    freeTree(root);

    return 0;
}