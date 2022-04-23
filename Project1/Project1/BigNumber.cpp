#include "BigNumber.h"
#include <vector>

BigNumber BigNumber::operator+(BigNumber a) {
	//reverse
	std::string bigTmp;
	std::string smallTmp;
	long long int size = 0;
	int whiBig = 0;
	if (dividend.size() > a.dividend.size()) 		whiBig = 0;
	else if (dividend.size() < a.dividend.size())	whiBig = 1;
	else {
		for (long long int i = 0; i < dividend.size(); i++) {
			if (dividend[dividend.size() - 1] > a.dividend[a.dividend.size() - 1]) {
				whiBig = 0;
				break;
			}
			else if (dividend[dividend.size() - 1] < a.dividend[a.dividend.size() - 1]) {
				whiBig = 1;
				break;
			}
			else {
				if (i == dividend.size() - 1) {
					whiBig = 0;
					break;
				}
				else {
					continue;
				}
			}
		}
	}
	if (whiBig == 0) {
		size = dividend.size();
		for (long long int i = 0; i < dividend.size(); i++)		bigTmp[i] = dividend[dividend.size() - i - 1];
		for (long long int i = 0; i < a.dividend.size(); i++)	smallTmp[i] = a.dividend[a.dividend.size() - i - 1];
	}
	else {
		size = a.dividend.size();
		for (long long int i = 0; i < dividend.size(); i++)		smallTmp[i] = dividend[dividend.size() - i - 1];
		for (long long int i = 0; i < a.dividend.size(); i++)	bigTmp[i] = a.dividend[a.dividend.size() - i - 1];
	}
	//
	std::string numerator;
	std::string denominator;

	std::string numTmp;
	int tmp = 0;
	//pos pos or veg veg
	if ((isNeg == 0 && a.isNeg == 0) || (isNeg == 1 && a.isNeg == 1) ){
		for (long long int i = 0; i < size; i++) {
			if (i < bigTmp.size() && i < smallTmp.size()) {
				tmp += bigTmp[i] - '0' + smallTmp[i] - '0';
				if (tmp < 10) {
					numTmp[i] = tmp + '0';
					tmp = 0;
				}
				else {
					numTmp[i] = (tmp - 10) + '0';
					tmp = 1;
				}
			}
			else if (i >= smallTmp.size()) {
				if (tmp == 1) {
					tmp += bigTmp[i] - '0';
					if (tmp < 10) {
						numTmp[i] = tmp + '0';
						tmp = 0;
					}
					else {
						numTmp[i] = (tmp - 10) + '0';
						tmp = 1;
					}
				}
				else {
					numTmp[i] = bigTmp[i];
				}
			}
		}
		if (isNeg == 0) {
			//answer is positive
		}
		else {
		//answer is negative
		}
	}
	//pos veg
	if ((isNeg == 0 && a.isNeg == 1) || (isNeg == 1 && a.isNeg == 0)) {
		for (long long int i = 0; i < size; i++) {
			if (i < bigTmp.size() && i < smallTmp.size()) {
				tmp += bigTmp[i] - smallTmp[i];
				if (tmp >= 0) {
					numTmp[i] = tmp + '0';
					tmp = 0;
				}
				else {
					numTmp[i] = (tmp + 10) + '0';
					tmp = -1;
				}
			}
			else if (i >= smallTmp.size()) {
				if (tmp == -1) {
					tmp += bigTmp[i] - '0';
					if (tmp >= 0) {
						numTmp[i] = tmp + '0';
						tmp = 0;
					}
					else {
						numTmp[i] = (tmp + 10) + '0';
						tmp = -1;
					}
				}
				else {
					numTmp[i] = bigTmp[i];
				}
			}
		}
		if (isNeg == 0 && a.isNeg == 1) {
			if (whiBig == 0) {
				//answer is positive
			}
			else {
				//answer is negative
			}
		}
		else {
			if (whiBig == 1) {
				//answer is positive
			}
			else {
				//answer is negative
			}
		}

	}
}
BigNumber BigNumber::operator+() {

}
BigNumber BigNumber::operator-(BigNumber a) {
	// alter the sign
	if (a.isNeg == true)	a.isNeg = false;
	else					a.isNeg = true;
	//reverse
	std::string bigTmp;
	std::string smallTmp;
	long long int size = 0;
	int whiBig = 0;
	if (dividend.size() > a.dividend.size()) 		whiBig = 0;
	else if (dividend.size() < a.dividend.size())	whiBig = 1;
	else {
		for (long long int i = 0; i < dividend.size(); i++) {
			if (dividend[dividend.size() - 1] > a.dividend[a.dividend.size() - 1]) {
				whiBig = 0;
				break;
			}
			else if (dividend[dividend.size() - 1] < a.dividend[a.dividend.size() - 1]) {
				whiBig = 1;
				break;
			}
			else {
				if (i == dividend.size() - 1) {
					whiBig = 0;
					break;
				}
				else {
					continue;
				}
			}
		}
	}
	if (whiBig == 0) {
		size = dividend.size();
		for (long long int i = 0; i < dividend.size(); i++)		bigTmp[i] = dividend[dividend.size() - i - 1];
		for (long long int i = 0; i < a.dividend.size(); i++)	smallTmp[i] = a.dividend[a.dividend.size() - i - 1];
	}
	else {
		size = a.dividend.size();
		for (long long int i = 0; i < dividend.size(); i++)		smallTmp[i] = dividend[dividend.size() - i - 1];
		for (long long int i = 0; i < a.dividend.size(); i++)	bigTmp[i] = a.dividend[a.dividend.size() - i - 1];
	}
	//
	std::string numerator;
	std::string denominator;

	std::string numTmp;
	int tmp = 0;
	//pos pos or veg veg
	if ((isNeg == 0 && a.isNeg == 0) || (isNeg == 1 && a.isNeg == 1)) {
		for (long long int i = 0; i < size; i++) {
			if (i < bigTmp.size() && i < smallTmp.size()) {
				tmp += bigTmp[i] - '0' + smallTmp[i] - '0';
				if (tmp < 10) {
					numTmp[i] = tmp + '0';
					tmp = 0;
				}
				else {
					numTmp[i] = (tmp - 10) + '0';
					tmp = 1;
				}
			}
			else if (i >= smallTmp.size()) {
				if (tmp == 1) {
					tmp += bigTmp[i] - '0';
					if (tmp < 10) {
						numTmp[i] = tmp + '0';
						tmp = 0;
					}
					else {
						numTmp[i] = (tmp - 10) + '0';
						tmp = 1;
					}
				}
				else {
					numTmp[i] = bigTmp[i];
				}
			}
		}
		if (isNeg == 0) {
			//answer is positive
		}
		else {
			//answer is negative
		}
	}
	//pos veg
	if ((isNeg == 0 && a.isNeg == 1) || (isNeg == 1 && a.isNeg == 0)) {
		for (long long int i = 0; i < size; i++) {
			if (i < bigTmp.size() && i < smallTmp.size()) {
				tmp += bigTmp[i] - smallTmp[i];
				if (tmp >= 0) {
					numTmp[i] = tmp + '0';
					tmp = 0;
				}
				else {
					numTmp[i] = (tmp + 10) + '0';
					tmp = -1;
				}
			}
			else if (i >= smallTmp.size()) {
				if (tmp == -1) {
					tmp += bigTmp[i] - '0';
					if (tmp >= 0) {
						numTmp[i] = tmp + '0';
						tmp = 0;
					}
					else {
						numTmp[i] = (tmp + 10) + '0';
						tmp = -1;
					}
				}
				else {
					numTmp[i] = bigTmp[i];
				}
			}
		}
		if (isNeg == 0 && a.isNeg == 1) {
			if (whiBig == 0) {
				//answer is positive
			}
			else {
				//answer is negative
			}
		}
		else {
			if (whiBig == 1) {
				//answer is positive
			}
			else {
				//answer is negative
			}
		}

	}
}
BigNumber BigNumber::operator-() {

}