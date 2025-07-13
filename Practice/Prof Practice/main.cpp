/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include "linkedListType.h"

using namespace std;
int main()
{
    //cout<<"Hello World";
    linkedListType myLL;
    myLL.insertFirst(40);
    myLL.insertFirst(30);
    myLL.insertFirst(20);
    cout<< "The list before the rotation is :" ;
    myLL.print();
  
    myLL.rotate();
    cout<< endl<< "The list after the rotation is :" ;
    myLL.print();

    //cout << endl
   
    int litem;
    if (myLL.deleteLast(litem)) {
        cout <<endl<< "List after the last is deleted:" ;
        myLL.print();
        cout <<endl << "The last item deleted is:" << litem<< endl;
    }
    


    return 0;
}