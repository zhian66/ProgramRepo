#include "BigNumber.h"
#include "vector"
#include "string"
using namespace std;

bool checkParentheses(const string& input);

bool isSetInt(const string& input);
bool isSetDec(const string& input);

int main() {
	string input;
	vector<string> varList;
	//BigNumber result;
	bool notError;
	while (getline(cin, input)) {
		notError = 1;
		// input error
		if (input[0] == NULL) {
			cout << "Input should not be empty." << endl;
			continue;
		}

		if (!checkParentheses(input)) {
			cout << "Parentheses Error" << endl;
			continue;
		}

		// Set Integer/Decimal A
		if (isSetInt(input)) {
			cout << "Set Integer." << endl;
		}
		else if (isSetDec(input)) {
			cout << "Set Decimal." << endl;
		}

		if (notError) {
			//result = input;
			//cout << result;
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


bool isSetInt(const string & input) {
	string strSet = "Set Integer";
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


