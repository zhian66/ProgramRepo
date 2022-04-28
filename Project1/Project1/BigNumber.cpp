#include "BigNumber.h"
#include <vector>


BigNumber::BigNumber() {
	isNeg = 0;
	//dividend = "0";
	digits.push_back(0);
	fractional.clear();
	remainder.clear();
}

BigNumber::BigNumber(std::string input) {
	if (input[0] == '-') {
		isNeg = 1;
		//dividend = input.substr(1);
	} else {
		isNeg = 0;
		//dividend = input;
	}
	for (auto c : input) if (c != '-') digits.push_back(c - '0');
	std::reverse(digits.begin(), digits.end());
	fractional.clear();
	remainder.clear();
}

BigNumber::BigNumber(long long nr) {
	if (nr < 0) {
		isNeg = 1;
		nr *= -1;
	}
	do {
		//dividend.push_back(nr % 10);
		digits.push_back(nr % 10);
		nr /= 10;
	} while (nr);
	std::reverse(digits.begin(), digits.end());
	fractional.clear();
	remainder.clear();
}

BigNumber::BigNumber(const BigNumber& a) {
	//dividend = a.dividend;
	isNeg = a.isNeg;
	digits = a.digits;
	fractional = a.fractional;
	remainder = a.remainder;
}

int Length(const BigNumber& a) {
	//return a.dividend.size();
	/*
	int size = a.digits.size();
	while (a.digits[size-1] != 0 && size > 0) {
		size--;
	}
	return size;
	*/
	return a.digits.size();
}

void printError() {
	std::cout << ERROR_MSG << std::endl;
}

bool operator<(const BigNumber& a, const BigNumber& b) {
	int n = Length(a), m = Length(b);
	if (a.isNeg && !b.isNeg) return true; // a:- b:+
	else if (!a.isNeg && b.isNeg) return false; // a:+ b:-
	if (n != m)
		return (n < m)&&(!a.isNeg); 
	// a:+ b:+ , len(a) < len(b) => true
	// a:- b:- , len(a) < len(b) => false
	/*
	while (n--)
		if (a.dividend[n] != b.dividend[n])
			return (a.dividend[n] < b.dividend[n]) && (!a.isNeg);
	*/
	while (n--) {
		if (a.digits[n] != b.digits[n]) {
			return (a.digits[n] < b.digits[n]) && (!a.isNeg);
		}
	}
	return false;
}

bool operator>(const BigNumber& a, const BigNumber& b) {
	return b < a;
}
bool operator>=(const BigNumber& a, const BigNumber& b) {
	return !(a < b);
}
bool operator<=(const BigNumber& a, const BigNumber& b) {
	return !(a > b);
}
bool operator==(const BigNumber& a, const BigNumber& b) {
	if (a.isNeg != b.isNeg) return false;
	if (Length(a) != Length(b)) {
		return false;
	}
	for (int i = 0; i < Length(a); i++) {
		if (a.digits[i] != b.digits[i]) return false;
	}
	return true;
}

BigNumber operator+(const BigNumber& a, const BigNumber& b) {
	BigNumber c;
	int i = 0, carry = 0;
	int m = Length(a), n = Length(b), size = m > n ? m+1 : n+1;
	c.digits.resize(size, 0);
	if (!a.isNeg && !b.isNeg) {
		for (i = 0; i < size; ++i) {
			if (i < m) c.digits[i] += a.digits[i];
			if (i < n) c.digits[i] += b.digits[i];
			if (carry) c.digits[i] += carry;
			carry = c.digits[i] / 10;
			c.digits[i] %= 10;
		}
		if (carry) 
			c.digits[i] += carry;
	} else if (a.isNeg && !b.isNeg) {
		// a:- b:+
		BigNumber temp = a;
		temp.isNeg = 0;
		c = b - temp;
	} else if (!a.isNeg && b.isNeg) {
		// a:+ b:-
		BigNumber temp = b;
		temp.isNeg = 0;
		c = a - temp;
	} else {
		BigNumber temp = a;
		temp.isNeg = 0;
		c = c + temp;
		temp = b;
		temp.isNeg = 0;
		c = c + temp;
		c.isNeg = 1;
	}
	

	return c;
}

BigNumber operator-(const BigNumber& a, const BigNumber& b) {
	BigNumber c;
	int i = 0, borrow = 0;
	int m = Length(a), n = Length(b), size = m > n ? m + 1 : n + 1;
	c.digits.resize(size, 0);
	if (!a.isNeg && !b.isNeg) {
		if (a > b) {
			for (i = 0; i < size; ++i) {
				if (i < m) c.digits[i] += a.digits[i];
				if (i < n) c.digits[i] -= b.digits[i];
				c.digits[i] -= borrow;
				if (c.digits[i] < 0) {
					borrow = 1;
					c.digits[i] += 10;
				} else {
					borrow = 0;
				}
			}
		} else {
			c = b - a;
			c.isNeg = 1;
		}
	} else if (a.isNeg && !b.isNeg) {
		// a:- b:+
		BigNumber temp = a;
		temp.isNeg = 0;
		c = temp + b;
		c.isNeg = 1;
	} else if (!a.isNeg && b.isNeg) {
		// a:+ b:-
		BigNumber temp = b;
		temp.isNeg = 0;
		c = a + temp;
	} else {
		// a:- b:- (- +)
		BigNumber temp1 = a;
		BigNumber temp2 = b;
		temp1.isNeg = 0;
		temp2.isNeg = 0;
		c = b - a;
	}
	return c;
}

BigNumber operator*(const BigNumber& a, const BigNumber& b) {
	BigNumber c;
	int m = Length(a), n = Length(b), size = m > n ? m : n;
	c.digits.resize(m+n, 0);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; j++) {
			c.digits[i + j] += a.digits[i] * b.digits[j];
		}
	}
	for (int i = 0; i < m + n - 1; i++) {
		if (c.digits[i] > 10) {
			c.digits[i+1] += c.digits[i] / 10;
			c.digits[i] %= 10;
		}
	}
	if (a.isNeg || b.isNeg) c.isNeg = 1;
	return c;
}

BigNumber operator/(const BigNumber& a, const BigNumber& b) {
	BigNumber c;
	bool vaild = false;
	for (auto n : b.digits) {
		if (n != 0) {
			vaild = true;
			break;
		}
	}
	if (!vaild) {
		printError();
		return c;
	}

	if (a == b) {
		c = 1;
	} else if (a < b) {
		c.remainder = a.digits;
		c.fractional = b.digits;
	} else {

	}
	
	if (a.isNeg || b.isNeg) c.isNeg = 1;
	return c;
}


/*
100/5 = 20
100/3 = 33 + 1/3
2/3 = 2/3
*/

/*
BigNumber BigNumber::operator+(const BigNumber& a) {
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
	return *this;
}
*/
/*
BigNumber BigNumber::operator+() {
	isNeg = false;
	return *this;
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
	return *this;
}
BigNumber BigNumber::operator-() {
	isNeg = true;
	return *this;
}

*/

BigNumber BigNumber::operator-() {
	isNeg = true;
	return *this;
}

BigNumber factorial(BigNumber a) {
	return a;
}

BigNumber Power(BigNumber a, BigNumber b) {
	BigNumber c = a;
	int times;
	return c;
}

std::ostream& operator<<(std::ostream& os, const BigNumber & num) {
	if (num.isNeg) os << '-';
	//os << num.dividend;
	bool lead = 1;
	for (int i = Length(num) - 1; i >= 0; i--) {
		if (num.digits[i] == 0) {
			if (!lead) {
				os << num.digits[i];
			} 
		} else {
			os << num.digits[i];
			lead = 0;
		}
	
	}
	return os;
}