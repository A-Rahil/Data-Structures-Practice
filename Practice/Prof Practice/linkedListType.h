#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node


struct nodeType
{
	int info;
	nodeType *link;
};



class linkedListType
{
public:

    bool isEmptyList() const;
      //Function to determine whether the list is empty.
      //Postcondition: Returns true if the list is empty, otherwise
      //    it returns false.

    void print() const;
      //Function to output the data contained in each node.
      //Postcondition: none

    int length() const;
      //Function to return the number of nodes in the list.
      //Postcondition: The value of count is returned.

    void destroyList();
      //Function to delete all the nodes from the list.
      //Postcondition: first = NULL, last = NULL, count = 0;

    void insertFirst(const int& newItem);
    bool deleteLast(int &oldItem);
    void rotate();
   // virtual bool search(const int& searchItem) const = 0;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list,
      //    otherwise the value false is returned.

  // virtual void insertFirst(const int& newItem) = 0;
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the beginning of the list, last points to
      //    the last node in the list, and count is incremented by
      //    1.

  //  virtual void insertLast(const int& newItem) = 0;
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the end of the list, last points to the
      //    last node in the list, and count is incremented by 1.

//    virtual void deleteNode(const int& deleteItem) = 0;
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing deleteItem is
      //    deleted from the list. first points to the first node,
      //    last points to the last node of the updated list, and
      //    count is decremented by 1.


    linkedListType();
      //default constructor
      //Initializes the list to an empty state.
      //Postcondition: first = NULL, last = NULL, count = 0;

     ~linkedListType();
      //destructor
      //Deletes all the nodes from the list.
      //Postcondition: The list object is destroyed.



//	virtual void doubleList() = 0;
	   //doubling all the list elements




protected:
    int count;   //variable to store the number of
                 //elements in the list
    nodeType *first; //pointer to the first node of the list
    nodeType *last;  //pointer to the last node of the list

};



bool linkedListType::isEmptyList() const
{
    return(first == NULL);
}


linkedListType::linkedListType() //default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
}


void linkedListType::destroyList()
{
    nodeType *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != NULL)   //while there are nodes in the list
    {
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL; first has already
                 //been set to NULL by the while loop
    count = 0;
}


void linkedListType::print() const
{
    nodeType *current; //pointer to traverse the list

    current = first;    //set current so that it points to
                        //the first node
    while (current != NULL) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}//end print


int linkedListType::length() const
{
    return count;
}  //end length



linkedListType::~linkedListType() //destructor
{
   destroyList();
}//end destructor

void linkedListType::insertFirst(const int& newItem)
{
   nodeType *nn;
   nn= new nodeType();
   assert(nn !=NULL);
   nn->info=newItem;
   nn->link=NULL;
   if (isEmptyList())
        first=last=nn;
    else {
        nn->link=first;
        first=nn;
    }
    count++;
   
}

bool linkedListType::deleteLast(int &oldItem)
{
    if (isEmptyList()) // zero item
        return false;
    else if (first==last){ // only one item
       oldItem= first->info;
       delete first;
       first=last=NULL;
    } 
    else { // multiple items
      oldItem=last->info;
      nodeType *p;
      p=first;
      while (p->link != last)
         p=p->link;
      p->link=NULL;
      delete last;
      last=p;
    }
    count--;
    return true;
   
}

void linkedListType::rotate() 
{
    if (isEmptyList()) // zero item
        return; // do nothing
    else if (first==last){ // only one item
        return; // do nothing
    } 
    else { // multiple items
      int item;
      deleteLast(item);
      insertFirst(item);
    }
}

#endif
