//Non member reverse print method
void printStackReverse(stackType<int> &S) {
    stackType<int> saveS(S), tempS;
    while (!saveS.isEmptyStack()) {
        int stop = saveS.top();
        saveS.pop();
        tempS.push(stop);
    }
    temps.print();
}
//Took the stack, created a copy of it, and then added it to a new stack, which basically reversed it.
void printStackRecur(stackType<int> &S) {
    if (S.isEmptyStack()) return;
    int sTop = S.top();
    S.pop();
    printStackRecur(S);
    cout << " " << sTop;

}
//As a member method
void reversePrint() {
    for (int i = 0; i < stackTop; i++) 
        cout << list[i] << " ";
}