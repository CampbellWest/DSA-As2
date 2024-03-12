#include "Tree.h"

int main() {

    srand(time(NULL));

    int num = getNum();

    printf("Inserting: %i\n\n", num);

    link root = initTree();

    printf("Inserted Order\n");

    for (int i = 0; i < num; i++){
        if (i == 0) {
            root = insert(root, randomLetter());
            continue;
        }
        insert(root, randomLetter());
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