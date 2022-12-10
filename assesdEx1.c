#include <stdlib.h>
#include <stdio.h>
// #include <unistd.h>


typedef struct node_t
    {
        struct node_t* parent;
        int value;
        struct node_t* left;
        struct node_t* right;
    } node_t; 




int search(node_t * node, int toFind) {

    // search algorithm is; test the node.value to see if it is grater or less than the value you are looking for, if the value you seek is less than node.value, follow left, otherwise follow right.
    // When found, return the node.
    while (node != NULL && toFind != node->value)
    {
        if (toFind < node->value)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
        
    }
    
    int search_result;
    if (node == NULL)
    {
        search_result = 0;
    }
    else
    {
        search_result = 1;
    }

    // return a 1 if found, and a 0 if not found
    return search_result;
}





node_t * createTree(int firstElem) {
    // create a new root node
    node_t *topNode = malloc(sizeof(node_t));

    topNode->parent = NULL; // can probably remove this by using a 'pNode' where relevant - check!
    topNode->value = firstElem;
    topNode->left = NULL;
    topNode->right = NULL;

    return topNode;
}





void destroyTree(node_t * node) {
    // free up the menory used for the data struct when done

    // Need to walk through the tree and delete the end (leaf) nodes, making sure we don't orphan any nodes.

    // To find the leaves, walk down the left nodes as far as possible, then come back up until you can go right, and then follow the left, come back up until you can go right etc - each time that you land on a leaf node, delete it and then continue at the parent node...

        // cnode = child node
        // pnode = parent node


    if (node != NULL) {

        node_t *cNode = node;
        node_t *pNode = NULL;
        printf("\nNode value = %d", node->value);
        // descend through tree in a leftmost direction until we reach a leaf
        while (cNode->parent != NULL || cNode->left != NULL || cNode->right != NULL)
        {
            if  (cNode->left != NULL || cNode->right != NULL)
            {
                printf("\nAbout to descend tree; Node value = %d", cNode->value);
                pNode = cNode;
                if (cNode->left != NULL)
                {
                    cNode = cNode->left;
                    printf("\nDescending tree to left; Node value = %d", cNode->value);
                }
                else if (cNode->right != NULL)
                {
                    cNode = cNode->right;
                    printf("\nDescending tree to right; Node value = %d", cNode->value);
                }
            }
            // make sure this isn't the root node
            else if (cNode->parent != NULL)
            {
                pNode = cNode->parent;
                printf("\nDeleted leaf cNode = %d, Ascending tree to parent; Node value = %d\n", cNode->value, pNode->value);
                // release the leaf
                free(cNode);

                cNode = NULL;
                cNode = pNode;
                // Need to update the left or right reference to NULL as the child leaf has been deleted!
                if (cNode->left != NULL)
                {
                    cNode->left = NULL;
                }
                else if (cNode->right != NULL)
                {
                    cNode->right = NULL;
                }
            }
        }
        // loop ends when only the root node remains
        printf("\nShould be at patrent, About to delete; Node value = %d\n", cNode->value);
        free(cNode);
        cNode = NULL;
    }
}




void insertNode(node_t * node, int elem) {
    // steps needed
    //search for and if not found create inode (using the elem as the value) 
    // if the node already exists then there's nothing to insert - but do we return anything to indicate this or just fail silently?
    printf("Hello from line 120!!: %i\n", elem);
    // sleep(1);

    if (!search(node, elem))
    {
        // cnode = child node
        // pnode = parent node
        // inode = node to insert
        printf("Hello from line 143!!: %i\n", elem);
        // Create node to insert and populate with values and NULLs for node pointers
        node_t *iNode = malloc(sizeof(node_t));
        if (!iNode) return;
        // iNode->parent is assigned below
        iNode->value = elem;
        printf("%i inserted\n", elem);
        iNode->left = NULL;
        iNode->right = NULL;
        
        
        
        node_t *cNode = node;
        node_t *pNode = NULL;
        while (cNode != NULL) 
        {
            pNode = cNode;
            if (iNode->value < cNode->value)
            {
                cNode = cNode->left;
                printf("Went left\n");
            }
            else
            {
                cNode = cNode->right;
                printf("Went right\n");
            }
        }

        iNode->parent = pNode; // is parent actually needed?

        if (pNode == NULL)
        {
            node = iNode; // it is possible that the root node can have previously been removed using 'delete' without destroying the tree
        }
        else if (iNode->value < pNode->value)
        {
            pNode->left = iNode;
            printf("\nHello from line 179!!: %i\n", elem);
        }
        else
        {
            pNode->right = iNode;
        }
    }

   // check if valToInsert is bigger or lower than current node
    // if bigger look at right, if smaller look at left - if the same then don't add
    // if left or right node doesn't exist then add this new node, otherwise repeat previous step


}



void delete(node_t * node, int elem) {

}
    // search the tree for the element.

    // 1. If the node to be deleted is a leaf, there is nothing else to do.
    // 2. If the node to be deleted has exactly one child, that child will move up to replace its parent.
    // 3. If the node to be deleted has two children, you need to find the successor, i.e. the value that would replace the one to be deleted. Typically, this is the smallest value in the right subtree.


int main() {
    // mycode here

    // use malloc to create the nodes
    // node_t rootNode = createTree(10);

    node_t *myTree;

    myTree = createTree(50);
    printf("\nSearch for 50: %i", search(myTree, 50));
    printf("\nSearch for 30: %i", search(myTree, 30));
    if (myTree == NULL)
    {
        printf("\nNull value!");
    }
    else
    {
        printf("\nnot null!");
        printf("\nNode->value is: %i\n", myTree->value);
    }

    printf("Hello from line 209!!: %p\n", myTree->left);
    insertNode(myTree, 30);
    printf("\nSearch for 50: %i", search(myTree, 50));
    printf("\nSearch for 30: %i", search(myTree, 30));
    printf("\nSearch for 20: %i", search(myTree, 20));
    printf("\nSearch for 200: %i", search(myTree, 200));




    // insertNode(myTree, 50);
    // insertNode(myTree, 30);
    insertNode(myTree, 20);
    insertNode(myTree, 40);
    insertNode(myTree, 70);
    insertNode(myTree, 60);
    insertNode(myTree, 80);

    printf("\nSearch for 50: %i", search(myTree, 50));
    printf("\nSearch for 30: %i", search(myTree, 30));
    printf("\nSearch for 20: %i", search(myTree, 20));
    printf("\nSearch for 200: %i", search(myTree, 200));

    destroyTree(myTree);
    printf("Tree destroyed! Or is it??; mytree = %i", myTree);
    printf("\nSearch for 50: %i", search(myTree, 50));
    printf("\nSearch for 30: %i", search(myTree, 30));
    printf("\nSearch for 20: %i", search(myTree, 20));
    printf("\nSearch for 200: %i", search(myTree, 200));


    // clean up when done
    // destroyTree(rootNode);

}









