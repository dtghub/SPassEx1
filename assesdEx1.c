



typedef struct node_t
    {
        int value;
        struct node_t* left;
        struct node_t* right;
    } node_t; 


int search(node_t * node, int toFind) {

}




node_t * createTree(int firstElem) {
    // Use arbtrary size of 100 node for now
    ptr = (node_t*) malloc(100);
    topNode.value = firstElem;
    return ptr;
}




void destroyTree(node_t * node) {
    // free up the menory used for the data struct when done
    free(node);
}




void insert(node_t * node, int elem) {

}



void delete(node_t * node, int elem) {

}



int main() {
    // mycode here

    // use malloc to create the nodes
    node_t rootNode = createTree(10)
}









