#include "stacks.h"
bool matchingParentheses() {
    char ch;
    StackArray<char> myStack(16);
    cin >> ch;
    while (ch != '.') {
        if (ch == '{' ||ch == '(' || ch == '[')
            myStack.push(ch);
        else if (ch == '}' || ch == ')' || ch == ']') {
            if ((myStack.peak() == '{' && ch == '}') || (myStack.peak() == '[' && ch == ']') || (myStack.peak() == '(' && ch == ')'))
                myStack.pop();
            else 
                return false;
        }
        cin >> ch;
    }
    return myStack.isEmpty();
}
int main() {
    cout << matchingParentheses();
    return 0;
}