#include "equationparser.h"

EquationParser::EquationParser()
{

}


int EquationParser::priority(char op) {
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': case '!': case '#': case '~': return 3;
    default:            return 0;
    }
}

int EquationParser::calculate(const string& input) {
    stack<char> temp;
    bool first = true;
    bool preNum = false;
    int sPtr = 0, len = 0;
    string str = "";

    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        if (c == ' ') continue;

        if ((c >= '0' && c <= '9') || c == '.') {
            if (first) {
                postfix.push_back(str);
                sPtr = i;
            }
            first = false;
            preNum = true;
            postfix[postfix.size()-1].push_back(c);
        } else {
            first = true;
            str = "";
        }

        if (priority(c) > 0) {
            if (c == '-' && !preNum) {
                c = '~';
            } else if (c == '+' && !preNum) {
                c = '#';
            }
            if (!temp.empty() && temp.top() != '(') {
                if (priority(temp.top()) >= priority(c)) {	// c <= top
                    do {
                        string tmp(1, temp.top());
                        postfix.push_back(tmp);
                        temp.pop();
                    } while (!temp.empty() && priority(temp.top()) >= priority(c));
                    temp.push(c);
                    preNum = false;
                } else {									// c > top
                    temp.push(c);
                    preNum = false;
                }
            } else {
                temp.push(c);
            }
            preNum = false;
        }

        if (c == '(') {
            temp.push(c);
            preNum = false;
        }
        if (c == ')') {
            while (!temp.empty()) {
                if (temp.top() == '(') {
                    temp.pop();
                    break;
                } else {
                    string tmp(1, temp.top());
                    postfix.push_back(tmp);
                    temp.pop();
                }
            }
        }
    }
    while (!temp.empty()) {
        string tmp(1, temp.top());
        postfix.push_back(tmp);
        temp.pop();
    }
    return sum();
}
