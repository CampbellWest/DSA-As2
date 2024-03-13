#include "Tree.h"

int main() {

    srand(time(NULL)); // for using system clock to generate random time 

    int num = getNum(); // gets number from 11-20

    printf("Inserting: %i\n\n", num);

    link root = initTree();

    printf("Inserted Order\n");

    for (int i = 0; i < num; i++){ // loops through random number from 11-20
        if (i == 0) {
            root = insert(root, randomLetter()); // inserts the root of the tree to sort from 
            continue;
        }
        insert(root, randomLetter()); // every other node after the root 
    }

    printf("\n\nInOrder\n");
    traverseInOrder(root);

    printf("\n\n");
    //searchTree(root);  // search for specific char 
    // is assignment write up search isnt said to be printed to screen 
    // but its in requirements so its //'d out 

    printf("Total nodes: %i\n\n", countNodes(root));

    printf("Tallest path: %i\n\n", getTreeHeight(root));

    freeTree(root);

    return 0;
}