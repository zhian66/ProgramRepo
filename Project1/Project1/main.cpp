#include "BigNumber.h"
using namespace std;


int main() {
	string input;
	while (getline(cin, input)) {
		if (input[0] == NULL)
			cout << "Input should not be empty." << endl;
		if (input[0] == 'S') {
			// Set Integer A = 123
			// Set Decimal B = 12.34
		}


		cout << input;
		BigNumber (input);
	}
}

