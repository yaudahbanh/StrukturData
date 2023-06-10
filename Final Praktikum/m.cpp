#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& expression) {
    stack<char> brackets;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty()) {
                return false;
            }
            
            char top = brackets.top();
            brackets.pop();
            
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return brackets.empty();
}

int main() {
    string expression;
    getline(cin, expression);

    if (isBalanced(expression)) {
        cout << "valdi" << endl;
    } else {
        cout << "unvaldi" << endl;
    }

    return 0;
}
