#include "BigNumber.h"
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool checkParentheses(const string& input);
bool checkVaildChar(const string& input);
bool checkCanCal(const string& input);

bool isSetInt(const string& input);
bool isSetDec(const string& input);

BigNumber sum();
BigNumber calculate(const string& input);
string replaceVar(const string& input);

vector<string> postfix;
vector<pair<string, BigNumber>> varList;
bool notError;


int main() {
	string input;
	//BigNumber result;
	vector<short> a, b, c;
	while (getline(cin, input)) {
		notError = 1;
		string cal;
		// input error
		if (input[0] == NULL) {
			cout << "Input should not be empty." << endl;
			continue;
		}

		if (!checkParentheses(input)) {
			cout << "Parentheses Error" << endl;
			continue;
		}
		
		if (!checkVaildChar(input)) {
			cout << "Invaild character." << endl;
			continue;
		}
		postfix.clear();
		

		// Set Integer/Decimal A
		if (isSetInt(input)) {
			string var;
			size_t found = input.find('=');
			if (found != std::string::npos) {
				if (found - 12 > 0) var = input.substr(12, found - 12);
				else {
					cout << "Invaild Variable" << endl;
					continue;
				}

				if (var[var.size() - 1] == ' ') var.erase(var.size() - 1);
				BigNumber num = input.substr(found + 1);
				num.Int();
				bool exist = 0;
				for (auto& v : varList) {
					if (v.first == var) {
						exist = 1;
						v.second = num;
					}
				}
				if (!exist) {
					varList.push_back(make_pair(var, num));
				}
			} else {
				notError = 0;
			}
			continue;

		} else if (isSetDec(input)){
			string var;
			size_t found = input.find('=');
			if (found != std::string::npos) {
				if (found - 12 > 0) var = input.substr(12, found - 12);
				else {
					cout << "Invaild Variable" << endl;
					continue;
				}
				if (var[var.size() - 1] == ' ') var.erase(var.size() - 1);
				BigNumber num = input.substr(found + 1);
				num.Dec();
				bool exist = 0;
				for (auto& v : varList) {
					if (v.first == var) {
						exist = 1;
						v.second = num;
					}
				}
				if (!exist) {
					varList.push_back(make_pair(var, num));
				}
			} else {
				notError = 0;
			}
			continue;
		} else {
			cal = replaceVar(input);
			if (!checkCanCal(cal)) {
				notError = 0;
			}
		}

		if (notError) {
			BigNumber result = calculate(cal);
			if (!result.Invaild && notError) cout << "Answer = " << result << endl;
		} else {
			cout << "Error-in-variable" << endl;
		}
	}
}


bool checkParentheses(const string& input) {
	size_t left = count(input.begin(), input.end(), '(');
	size_t right = count(input.begin(), input.end(), ')');
	if (left != right) 
		return false;
	size_t found = input.find("()");
	if (found != std::string::npos)
		return false;
	return true;
}

bool checkVaildChar(const string& input) {
	string vaildStr = "0123456789()+-*/=!.^abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	for (char c : input) {
		size_t found = vaildStr.find(c);
		if (found == string::npos) {
			return false;
		}
	}
	return true;
}

bool checkCanCal(const string& input) {
	string vaildStr = "0123456789()+-*/=!.^ ";
	for (char c : input) {
		size_t found = vaildStr.find(c);
		if (found == string::npos) {
			return false;
		}
	}
	return true;
}

bool isSetInt(const string & input) {
	string strSet = "Set Integer ";
	int i = 0;
	if (input.size() < strSet.size()) return false;
	for (char s : strSet) {
		if (s != input[i]) 
			return false;
		i++;
	}
	return true;
}

bool isSetDec(const string& input) {
	string strSet = "Set Decimal";
	int i = 0;
	if (input.size() < strSet.size()) return false;
	for (char s : strSet) {
		if (s != input[i])
			return false;
		i++;
	}
	return true;
}

bool isNum(string input) {
	for (auto c : input) {
		if ((c < '0' || c > '9') && c != '.') {
			return false;
		}
	}
	return true;
}

bool isOper(string s) {
	string operStr = "+-*/=!^#~";
	size_t found = operStr.find(s);
	if (found == string::npos) {
		return false;
	}
	return true;
}

string replaceVar(const string& input) {
	string result = input;
	for (auto var : varList) {
		size_t found = result.find(var.first);
		while (found != string::npos) {
			result.replace(found, var.first.size(), var.second.to_string());
			found = result.find(var.first);
		}
	}
	return result;
}


BigNumber sum() {
	stack<BigNumber> numStack;
	BigNumber num;
	/*
	for (auto n : postfix) {
		cout << n << " ";
	}
	cout << endl;
	*/
	
	
	
	for (int i = 0; i < postfix.size(); i++) {
		string str = postfix[i];
		if (isNum(str)) {
			numStack.push(str);
			continue;
		}
		if (str == "+") {
			if (!numStack.empty()) {
				num = numStack.top();
				numStack.pop();
			}
			if (!numStack.empty()) {
				num = num + numStack.top();
				numStack.pop();
			}
			numStack.push(num);
		}
		if (str == "-") {
			if (!numStack.empty()) {
				num = numStack.top();
				numStack.pop();
			}
			if (!numStack.empty()) {
				num = numStack.top() - num;
				numStack.pop();
			}
			numStack.push(num);
		} 
		if (str == "*") {
			if (!numStack.empty()) {
				num = numStack.top();
				numStack.pop();
			}
			if (!numStack.empty()) {
				num = numStack.top() * num;
				numStack.pop();
			}
			numStack.push(num);
		} 
		if (str == "/") {
			BigNumber empty;
			if (!numStack.empty()) {
				num = numStack.top();
				numStack.pop();
			}
			if (num == empty) {
				cout << "Invaild divide" << endl;
				notError = 0;
				break;
			}
			if (!numStack.empty()) {
				num = numStack.top() / num;
				numStack.pop();
			}
			numStack.push(num);
		} 
		if (str == "^") {
			if (!numStack.empty()) {
				num = numStack.top();
				numStack.pop();
			}
			if (!numStack.empty()) {
				num = Power(numStack.top(), num);
				numStack.pop();
			}
			numStack.push(num);
		}
		if (str == "!") {
			if (!numStack.empty()) {
				num = factorial(numStack.top());
				numStack.pop();
			}
			numStack.push(num);
		}
		if (str == "~") {
			if (!numStack.empty()) {
				num = -numStack.top();
				numStack.pop();
			}
			numStack.push(num);
		}
		if (str == "#") {
		}
	}
	
	return numStack.top();
}

int priority(char op) {
	switch (op) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': case '!': case '#': case '~': return 3;
	default:            return 0;
	}
}

BigNumber calculate(const string& input) {
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


/*
計算式: 7 * ( 9 + 9 - ( 5 - ( 7 + 10 ) ) + ( 3 - 8 ) ) 
後序式: 7 9 9 + 5 7 10 + --3 8 - +*


計算式: 3 * ( ( 2 - 8 ) / 9 ) + 7 * ( 5 * ( 9 / 8 ) )
後序式: 3 2 8 - 9 / * 7 5 9 8 / * * +


計算式: 3 + 3 / ( 10 * ( 5 * ( 6 / 2 ) * ( 3 + 11 ) ) )
後序式: 3 3 10 5 6 2 / * 3 11 + * * / + 


計算式: ( 10 - 7 ) / ( 5 + 11 - ( 8 * 11 - 6 ) + 8 ) = -0.05
後序式: 10 7 - 5 11 + 8 11 * 6 - - 8 + /


計算式:	 ( 10 + 5 + ( 9 * ( 5 + 6 ) - 4 ) ) * 7 / 2 = 385
10 5 + 9 5 6 + * 4 - + 7 * 2 /

*/
