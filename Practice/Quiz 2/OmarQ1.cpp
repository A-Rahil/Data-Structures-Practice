//Insert first method for an ordered list
//This method will be the standard insert method that we know
//Because you have to insert it right where it belongs and we have to maintain the order

//Implementation with a template:
template <class T>
void OrderedList<T>::insert(const T& item) {
    //First, create a node to use for insertion, along with the pointers and bool value we need
    nodeType<T> *newNode = new nodeType();
    newNode->info = item;
    newNode->link = NULL;
    nodeType<T> *current = head;
    nodeType<T> *behind = NULL;
    bool found = false;
    //Then, consider the cases:
    //Is the list empty or not?
    if (head == NULL) {
        head = newNode;
        tail = newNode; //Empty list so both head and tail will point to the same location
    }
    //Now, what if the list isn't empty? Multiple subcases here but we group them all together under the same else statement (the list isn't empty)
    else {
        //What if the item is supposed to go in the first node because it is the smallest?
        if (item < head->info) {
            newNode->link = head; //newNode is now pointing at the first element
            head = newNode; //The head is now pointing at the newNode, which has become our first element
            //What if this list has a single element? Do a check
            if (head->link == NULL) 
                tail = newNode; //If yes, then point our tail to this single node as well
            count++;
        }
        //What if the location is not supposed to be first? Ok, we do a search in that case and find the appropriate location
        else {
            while (current != NULL && !found) { //Continue the loop until we either reach the end or until we find the spot
                if (item > current->info) { //Check every loop, if we go over the right spot, then we should stop immediately without updating current
                    found = true;
                }
                else {
                    behind = current;
                    current = current->link;    //Keep traversing
                }
            }
            //We will exit the loop when the perfect spot is found
            if (found) //if we found the perfect spot, then add it there
                {
                    //Make the new node point to the next element
                    newNode->link = current;
                    //Connect the link with the previous pointer
                    behind->link = newNode;
                    //If the item got added to the end, then make the tail point to it as well
                    if (current == NULL) {
                        tail = newNode;
                    }
                }
                count++;
        }
    }
}
