//Return the number of nodes within a linked list
int numberOfNodes(nodeType *current) {
    if (current == NULL)
        return 0;
    else
        return 1 + numberOfNodes(current->link);
}