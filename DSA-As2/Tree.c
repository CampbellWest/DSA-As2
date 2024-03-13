#include "Tree.h"

void clearBuffer() { // clears std when searching for chars 
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        continue;
}

char randomLetter() {
    return (rand() % (122 - 97 + 1) + 97); // returns a-z values for tree input 
}

int getNum() {
    return rand() % (20 - 11 + 1) + 11; // picks how many nodes to insert 
}

link initTree() {
    link temp = (link)malloc(sizeof(struct TreeNode)); // allocates memory for the trees root in main 
    return (temp = NULL);
}

link insert(link root, char data) {

    if (root == NULL) { // once youre at the end of one side of the tree
        printf("%c->", data);
        return newNode(data); // use that data to create a new node which is set to the previous
    }                         // nodes right or left depending 

    if (data < root->data) // if the letter we're trying to insert comes before this nodes letter 
        root->pLeft = insert(root->pLeft, data); // go down the left tree and try again 
    else if (data > root->data)
        root->pRight = insert(root->pRight, data); // same process with the right 
    
    return root; // this just returns the tree back to main if a letter that has already been added gets passed 
}

link newNode(char data) {

    link temp = (link)malloc(sizeof(struct TreeNode)); // new memory for node 

    temp->data = data; // set to the data 
    temp->pLeft = temp->pRight = NULL; // left and right children nodes are set to null 

    return temp;
}

void searchTree(link root) {

    char c;

    do {
        printf("\nSearch for char: ");
        if (!isalpha(c = getc(stdin))) // gets char input 
            break;

        clearBuffer();

        if (search(root, c) == NULL) 
            printf("Not in tree\n");
        else
            printf("Found in tree\n");

    } while (1);

    printf("\n\n");
}

link search(link root, char data) {

    if (root == NULL || root->data == data) // called recursively until either we're at a NULL node (you fell off a leaf node)
        return root;                        // or you found a node that has data equal to the data youre searching for 

    if (root->data < data)                // if the data at this node is less than what we're looking for search the right 
        return search(root->pRight, data);

    return search(root->pLeft, data); // else search the left 
}

int countNodes(link root) {

    if (root == NULL)
        return 0;

    return (countNodes(root->pLeft) + countNodes(root->pRight) + 1);
    // each node is searched in its left and right tree until the end
    // once it hits a null node it returns a 0 
    // for example, if a leaf node calls this it has 2 null pointers so it will
    // return (0 + 0 + 1) 
    // counting that last node as one which is then returned to its parent
    // along with its sibling node (if there is one, we'll say there is) 
    // to return (1 + 1 + 1) 
}

int getTreeHeight(link root) {

    int leftHeight, rightHeight;               // goes down the tree until null nodes which then returns -1 to its parent + 1 (return (-1 + 1)
                                               // this the current nodes left sub tree height and if the right sub tree has a value bigger then         
    if (root == NULL)                          // the left the right tree value + 1 will be return and vise versa      
        return -1;                             // this will go back up the tree checking every nodes right and left paths to see which is bigger 
                                               // then adding 1 to the larger to continue counting the larger tree height      
    leftHeight = getTreeHeight(root->pLeft);
    rightHeight = getTreeHeight(root->pRight);

    if (leftHeight > rightHeight)
        return (leftHeight + 1);
    else
        return (rightHeight + 1);
}

void freeTree(link root) { // uses post order traversing to free nodes after they have been 
    if (root == NULL)      // traversed as to not free them before you free their children 
        return;

    freeTree(root->pRight);
    freeTree(root->pLeft);
    //printf("%c freed\n", root->data);
    free(root);
}

void traverseInOrder(link root) { // InOrder traverse which goes down the whole left tree until NULL then process the node
    if (root == NULL)             // then does the whole right tree
        return;

    traverseInOrder(root->pLeft);
    printf("%c->", root->data);
    traverseInOrder(root->pRight);
}

//************************************

void traversePreOrder(link root) {
    if (root == NULL)
        return;

    printf("%c->", root->data);
    traversePreOrder(root->pLeft);
    traversePreOrder(root->pRight);
}

void traversePostOrder(link root) {        // other traversals i used for testing but not in requirements 
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

//************************************