#include <stdlib.h>



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
        if (toFind < node->value) {
            node = node->left
        } else
        {
            node = node->right
        }
        
    }
    
    int search_result;
    if (node == NULL) {
        search_result = 0;
    } else {
        search_result = 1;
    }

    // return a 1 if found, and a 0 if not found
    return search_result;
}




node_t * createTree(int firstElem) {
    // create a new root node
    node_t *topNode = malloc(sizeof(node_t));

    topNode->parent = NULL;
    topNode->value = firstElem;
    topNode->left = NULL;
    topNode->right = NULL;

    return topNode;
}




void destroyTree(node_t * node) {
    // free up the menory used for the data struct when done

    // Need to walk through the tree and delete the end (leaf) nodes, making sure we don't orphan any nodes.

    // To find the leaves, walk down the left nodes as far as possible, then come back up until you can go right, and then follow the left, come back up until you can go right etc - each time that you land on a leaf node, delete it and then continue at the parent node...

    free(node);
}




void insert(node_t * node, int elem) {
    // steps needed
    //search for and if not found create inode (using the elem as the value) 
    // if the node already exists then there's nothin to insert - but do we return anything to indicate this or just fail silently?

    if (!search(node, elem)) {
        // cnode = child node
        // pnode = parent node
        // inode = node to insert
        
        
        // Create node to insert and populate with values and NULLs for node pointers
        node_t *iNode = malloc(sizeof(node_t));
        iNode->parent = NULL;
        iNode->value = elem;
        iNode->left = NULL;
        iNode->right = NULL;
        
        
        
        node_t *cNode = node;
        node_t *pNode;
        while (cNode != NULL) {
            pNode = cNode;
            if (iNode->value < cNode->value) {
                cNode = cNode->left;
            } else {
                cNode = cNode->right;
            }
        }

        iNode->parent = cNode;

        if (pNode == NULL) {
            node = iNode;
        } else if (iNode->value < cNode->value) {
            pNode->left = iNode;
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








    // clean up when done
    destroyTree(rootNode);

}









