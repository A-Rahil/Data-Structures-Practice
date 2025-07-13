//Print a Linked List normally
//Assuming that all the headers have been implemented, this is how it would look like
void printLL(nodeType *current) {
    if (current != NULL) {
        cout << current->info;  //Print the current info
        printLL(current->link); //Recurse into the rest of the linked list
    }
}