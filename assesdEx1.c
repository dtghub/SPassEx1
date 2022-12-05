



typedef struct node_t
    {
        int value;
        struct node_t* left;
        struct node_t* right;
    } node_t; 


int search(node_t * node, int toFind) {

    // search algorithm is; test the node.value to see if it is grater or less than the value you are looking for, if the value you seek is less than node.value, follow left, otherwise follow right.
    // When found, retunr the node.





}




node_t * createTree(int firstElem) {
    // create a new root node
    node_t *topNode = malloc(1);
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



node_t walk_insert(node_t *node, int elem){
    if (elem < node->value) {
            if (node->left != NULL) {

            }
    }
}




void insert(node_t * node, int elem) {
    // steps needed
    if (elem != node->value) {
        
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









