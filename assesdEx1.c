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


void make_null(node_t * node) {
    if (node == NULL) return;
    node->left = NULL;
    node->right = NULL;
    node->value = NULL;
    node->parent = NULL;
}

int tree_exists(node_t * node) {
    if (node == NULL)
    {
        return 0;
    }
    else if (node->value == NULL)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}


node_t *return_node(node_t * node, int toFind) {
    // search algorithm is; test the node.value to see if it is grater or less than the value you are looking for, if the value you seek is less than node.value, follow left, otherwise follow right.
    // When found, return the node.
    if (node == NULL) return NULL;
    if (node->value == NULL) return NULL;

    while (node != NULL)
    {
        if (toFind == node->value)
        {
            return node;
        }
        else if (toFind < node->value)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
        
    }
    
    return node;
}






int search(node_t * node, int toFind) {

    node_t *search_node = NULL;
    search_node = return_node(node, toFind);

    int search_result;
    if (search_node == NULL)
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
    if (!topNode) return NULL;

    make_null(topNode);
    topNode->value = firstElem;
    return topNode;
}





node_t * destroyTree(node_t * node) {
    // free up the menory used for the data struct when done

    // Walks through the tree and delete the end (leaf) nodes, making sure we don't orphan any nodes.

    // To find the leaves, walk down the left nodes as far as possible, then come back up until you can go right, and then follow the left, come back up until you can go right etc - each time that you land on a leaf node, delete it and then continue at the parent node...

        // cnode = child node
        // pnode = parent node


    if (node == NULL) return node;
    node_t *cNode = node;
    node_t *pNode = NULL;
    if (node->value != NULL)
    {
        // descend through tree in a leftmost direction until we reach a leaf
        while (cNode->parent != NULL || cNode->left != NULL || cNode->right != NULL)
        {
            if  (cNode->left != NULL || cNode->right != NULL)
            {
                pNode = cNode;
                if (cNode->left != NULL)
                {
                    cNode = cNode->left;
                }
                else if (cNode->right != NULL)
                {
                    cNode = cNode->right;
                }
            }
            // make sure this isn't the root node
            else if (cNode->parent != NULL)
            {
                pNode = cNode->parent;
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
    }
    make_null(cNode); // this is probably an unnecessary precauion against the free function failing
    free(cNode);
    cNode = NULL;
    return cNode;
}




void insert(node_t * node, int elem) {
    // steps needed
    //search for and if not found create inode (using the elem as the value) 
    if (node == NULL) return;

    if (!search(node, elem))
    {
        // cnode = child node
        // pnode = parent node
        // inode = node to insert
        // Create node to insert and populate with values and NULLs for node pointers
        node_t *iNode = malloc(sizeof(node_t));
        if (!iNode) return;
        // iNode->parent is assigned below
        iNode->value = elem;
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
            }
            else
            {
                cNode = cNode->right;
            }
        }

        iNode->parent = pNode;

        if (pNode->value == NULL)
        {
            node->value = iNode->value; // it is possible that the root node can have previously been 'deleted' using 'delete' without destroying the tree, in which case the root node's value properety will have been set to NULL
        }
        else if (iNode->value < pNode->value)
        {
            pNode->left = iNode;
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
    // need to get node that elem points to

    if (node == NULL) return;
    if (node->value == NULL) return;

    
    node_t *dNode = return_node(node, elem);

    if (dNode != NULL)
    {
        node_t *lNode = dNode->left;
        node_t *rNode = dNode->right;
        node_t *pNode = dNode->parent;
        // search the tree for the element.

        // 1. If the node to be deleted is a leaf, there is nothing else to do.

        if (lNode == NULL && rNode == NULL)
        {
            if (pNode != NULL)
            {
                if (pNode->left == dNode)
                {
                    pNode->left = NULL;
                }
                else
                {
                    pNode->right = NULL;
                }
            }
            // If the node is the last node in the tree, mark it's contents (i.e. value in this case) as null, but do not delete it, as there is no way to indicate to the code calling this function that the tree is now empty.
            // If we freed the root node the code calling would still have a pointer, but it would be to an unallocated block of memory.
            if (dNode->parent == NULL)
            {
                make_null(dNode);
            }
            else
            {
                make_null(dNode);
                free(dNode);
                dNode = NULL;
            }
            return;
        }
    


        // 2. If the node to be deleted has exactly one child, that child will move up to replace its parent.


        else if (lNode == NULL ^ rNode == NULL)
        {
            if (lNode != NULL)
            {
                pNode->left = lNode;
                lNode->parent = pNode;
            }
            else
            {
                pNode->right = rNode;
                rNode->parent = pNode;
            }
            free(dNode);
            dNode = NULL;
            return;
        }




        // 3. If the node to be deleted has two children, you need to find the successor, i.e. the value that would replace the one to be deleted. Typically, this is the smallest value in the right subtree.


        // descend the right subtree to find the smallest node in the subtree


        else
        {
            // use sNode to track the seek to the smallest node in the rigth subtree of node
            node_t *sNode = rNode;
            while (sNode->left != NULL)
            {
                sNode = sNode->left;
            }

            // copy the node's data (in this case that is just the value property), overwriting that of the node to be deleted
            dNode->value = sNode->value;
            // now the original sNode needs to be deleted
            delete(rNode, sNode->value);
        }
    }
}



int main() {
    // mycode here

    // use malloc to create the nodes
    // node_t rootNode = createTree(10);
    int treeStatus;
    node_t *myTree;

    myTree = createTree(50);
    if (!myTree) printf("ERROR");
    delete(myTree,50);
    printf("Search for 50: %i\n", search(myTree, 50));
    printf("Search for 30: %i\n", search(myTree, 30));
    treeStatus = tree_exists(myTree);
    if (treeStatus == 2)
    {
        printf("\nTree found!\n");
        printf("\nNode->value is: %i\n", myTree->value);
    }
    else if (treeStatus == 0)
    {
        printf("\nTree does not exist");
    }
    else
    {
        printf("\nTree is empty");
    }

    myTree = destroyTree(myTree);
    treeStatus = tree_exists(myTree);
    if (treeStatus == 2)
    {
        printf("\nTree found!\n");
        printf("\nNode->value is: %i\n", myTree->value);
    }
    else if (treeStatus == 0)
    {
        printf("\nTree does not exist");
    }
    else
    {
        printf("\nTree is empty");
    }

    myTree = createTree(50);
    printf("Hello from line 209!!: %p\n", myTree->left);
    insert(myTree, 30);
    printf("\nSearch for 50: %i", search(myTree, 50));
    printf("\nSearch for 30: %i", search(myTree, 30));
    printf("\nSearch for 20: %i", search(myTree, 20));
    printf("\nSearch for 200: %i", search(myTree, 200));




    // insert(myTree, 50);
    // insert(myTree, 30);
    insert(myTree, 20);
    insert(myTree, 40);
    insert(myTree, 70);
    insert(myTree, 75);
    insert(myTree, 60);
    insert(myTree, 80);
    insert(myTree, 200);
    insert(myTree, 10);
    insert(myTree, 5);
    insert(myTree, 8);
    insert(myTree, 35);
    insert(myTree, 45);
    insert(myTree, 47);

    // delete()
    delete(myTree, 50);
    delete(myTree, 30);
    printf("deteted node\n");



    printf("\nSearch for 80: %i", search(myTree, 80));
    printf("\nSearch for 75: %i", search(myTree, 75));
    printf("\nSearch for 200: %i", search(myTree, 200));
    printf("\nSearch for 50: %i", search(myTree, 50));
    printf("\nSearch for 40: %i", search(myTree, 40));
    printf("\nSearch for 30: %i", search(myTree, 30));
    printf("\nSearch for 20: %i", search(myTree, 20));
    printf("\nSearch for 10: %i", search(myTree, 10));
    printf("\nSearch for 5: %i", search(myTree, 5));
    printf("\nSearch for 200: %i", search(myTree, 200));

    // sleep(10);
    myTree = destroyTree(myTree);
    treeStatus = tree_exists(myTree);
    if (treeStatus == 2)
    {
        printf("\nTree found!\n");
        printf("\nNode->value is: %i", myTree->value);
    }
    else if (treeStatus == 0)
    {
        printf("\nTree does not exist");
    }
    else
    {
        printf("\nTree is empty");
    }

    // printf("Tree destroyed! Or is it??; mytree = %i", myTree);
    printf("\nSearch for 50: %i", search(myTree, 50));
    printf("\nSearch for 30: %i", search(myTree, 30));
    printf("\nSearch for 20: %i", search(myTree, 20));
    printf("\nSearch for 200: %i", search(myTree, 200));


    // clean up when done
 
}









