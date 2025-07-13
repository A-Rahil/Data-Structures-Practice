#include "stacks.h"
int postFix() {
    char ch;
    StackArray<int> postFixCalc(30);
    cout << "Please enter an expression: ";
    cin >> ch;
    while (ch != '.') {
        if (ch == '+' || ch == '*' || ch == '/' || ch == '-') {
            int first = postFixCalc.peak();
            postFixCalc.pop();
            int second = postFixCalc.peak();
            postFixCalc.pop();
            switch (ch) {
                case '+': 
                    postFixCalc.push(second + first); 
                    break;
                case '-': 
                    postFixCalc.push(second - first); 
                    break;
                case '*': 
                    postFixCalc.push(second * first); 
                    break;
                case '/': 
                    postFixCalc.push(second / first); 
                    break;
            }
        }
        else {
            postFixCalc.push(static_cast<int>(ch - '0'));   //Debugged by ChatGPT, corrects the conversion
        }
        cin >> ch;
    }
    return postFixCalc.peak();
}

int main() {
    cout << postFix();
    return 0;
}