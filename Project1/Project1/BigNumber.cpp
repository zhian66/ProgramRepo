#include "BigNumber.h"
#include <vector>
#include <unordered_map>
#define ERROR_MSG "Invaild Number"


BigNumber::BigNumber() {
	isNeg = 0;
	isDec = 0;
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
	size_t found = input.find_last_of(".");
	if (found != std::string::npos) {
		isDec = 1;
		for (int i = 0; i < found; i++) {
			char c = input[i];
			if (c == '-' || c == '.') {}
			else if (c == ' ') {}
			else digits.push_back(c - '0');
		}
		std::reverse(digits.begin(), digits.end());

		std::string decimal = "";
		for (int i = found + 1; i < input.size(); i++) {
			char c = input[i];
			if (c == '-' || c == '.') {} 
			else if (c == ' ') {} 
			else { 
				decimal += c; 
			}
		}
		std::cout << "decimal: " << decimal << std::endl;
	} else {
		isDec = 0;
		for (auto c : input) if (c != '-') digits.push_back(c - '0');
		std::reverse(digits.begin(), digits.end());
		fractional.clear();
		remainder.clear();
	}

}

BigNumber::BigNumber(int nr) {
	isDec = 0;
	isNeg = 0;
	if (nr < 0) {
		isNeg = 1;
		nr *= -1;
	}
	do {
		//dividend.push_back(nr % 10);
		digits.push_back(nr % 10);
		nr /= 10;
	} while (nr);
	fractional.clear();
	remainder.clear();
}

BigNumber::BigNumber(double n) {
	std::cout << "Double:" << std::endl;
	isDec = 1;
	isNeg = 0;
	if (n < 0) {
		isNeg = 1;
		n *= -1;
	}
	int nr = n;
	double dec = (n - nr);
	do {
		//dividend.push_back(nr % 10);
		digits.push_back(nr % 10);
		nr /= 10;
	} while (nr);
	std::cout << nr << " " << dec << std::endl;
	std::string decimal = std::to_string(dec);
	decimal = decimal.erase(0, decimal.find('.') + 1);
	std::cout << "decimal: " << decimal << std::endl;

	fractional.clear();
	remainder.clear();
}

BigNumber::BigNumber(const BigNumber& a) {
	//dividend = a.dividend;
	isNeg = a.isNeg;
	isDec = a.isDec;
	digits = a.digits;
	fractional = a.fractional;
	remainder = a.remainder;
}

void printError() {
	std::cout << ERROR_MSG << std::endl;
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

bool geq(const std::vector<short>& a, const std::vector<short>& b) {
	if (a.size() > b.size()) return true;
	else if (a.size() < b.size()) return false;
	else {
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a[i] < b[i]) return false;
		}
	}
	return true;
}

std::vector<short> add(const std::vector<short>& a, const std::vector<short>& b) {
	std::vector<short> c;
	int i = 0, carry = 0;
	int m = a.size(), n = b.size(), size = m > n ? m + 1 : n + 1;
	c.resize(size, 0);
	for (i = 0; i < size; ++i) {
		if (i < m) c[i] += a[i];
		if (i < n) c[i] += b[i];
		if (carry) c[i] += carry;
		carry = c[i] / 10;
		c[i] %= 10;
	}
	if (carry)
		c[i] += carry;
	return c;
}
std::vector<short> minus(const std::vector<short>& a, const std::vector<short>& b) {
	std::vector<short> c;
	int i = 0, borrow = 0;
	int m = a.size(), n = b.size(), size = m > n ? m + 1 : n + 1;
	c.resize(size, 0);
	for (i = 0; i < size; ++i) {
		if (i < m) c[i] += a[i];
		if (i < n) c[i] -= b[i];
		c[i] -= borrow;
		if (c[i] < 0) {
			borrow = 1;
			c[i] += 10;
		} else {
			borrow = 0;
		}
	}
	return c;
}
std::vector<short> mul(const std::vector<short>& a, const std::vector<short> & b) {
	std::vector<short> c;
	int m = a.size(), n = b.size(), size = m > n ? m : n;
	c.resize(m+n, 0);
	int i = 0, j = 0;
	int carry = 0;
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j)
			c[i + j] += a[i] * b[j];
	}

	for (i = 0; i < m + n - 1; ++i) {
		if (c[i] > 10) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
		carry = c[i] / 10;
		c[i] %= 10;
	}
	return c;
}

std::vector<short> divide(const std::vector<short>& a, const std::vector<short>& b) {
	std::vector<short> c(1,0);
	std::vector<short> tmp;
	auto x = a;
	int m = a.size(), n = b.size(), size = m > n ? m : n;
	while (geq(x, b)) {
		auto t = b;
		for (int i = 0; geq(x, c); i++) {
			x = minus(x, c);
			for (int j = 0; j < i; j++) {
				tmp.push_back(0);
			}

			tmp.push_back(1);
			c = add(c, tmp);
			c.insert(c.begin(), 0);
		}
	}
	return c;
}
/*
123 / 3
123 30 = 40
(123-120)=3
3/3 = 1
3-3 = 0


*/


/*
std::string fractionToDecimal(int numerator, int denominator) {
	long numeratorLong = numerator;
	long denominatorLong = denominator;
	if (numeratorLong % denominatorLong == 0) {
		return std::to_string(numeratorLong / denominatorLong);
	}

	std::string ans;
	if (numeratorLong < 0 ^ denominatorLong < 0) {
		ans.push_back('-');
	}

	// 整数部分
	numeratorLong = abs(numeratorLong);
	denominatorLong = abs(denominatorLong);
	long integerPart = numeratorLong / denominatorLong;
	ans += std::to_string(integerPart);
	ans.push_back('.');

	// 小数部分
	std::string fractionPart;
	std::unordered_map<long, int> remainderIndexMap;
	long remainder = numeratorLong % denominatorLong;
	int index = 0;
	while (remainder != 0 && !remainderIndexMap.count(remainder)) {
		remainderIndexMap[remainder] = index;
		remainder *= 10;
		fractionPart += std::to_string(remainder / denominatorLong);
		remainder %= denominatorLong;
		index++;
	}
	if (remainder != 0) { // 有循环节
		int insertIndex = remainderIndexMap[remainder];
		fractionPart = fractionPart.substr(0, insertIndex) + '(' + fractionPart.substr(insertIndex);
		fractionPart.push_back(')');
	}
	ans += fractionPart;

	return ans;
}
*/

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
	if (a.isDec != b.isDec) return false;
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
		c.digits = add(a.digits, b.digits);
		/*
		for (i = 0; i < size; ++i) {
			if (i < m) c.digits[i] += a.digits[i];
			if (i < n) c.digits[i] += b.digits[i];
			if (carry) c.digits[i] += carry;
			carry = c.digits[i] / 10;
			c.digits[i] %= 10;
		}
		if (carry) 
			c.digits[i] += carry;
		*/
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
	if (a == b) {
		c = 0;
		return c;
	}
	if (!a.isNeg && !b.isNeg) {
		if (a > b) {
			c.digits = minus(a.digits, b.digits);
			/*
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
			*/
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
	c.digits = mul(a.digits, b.digits);
	/*
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
	*/
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
		c = 0;
		c.remainder = a.digits;
		c.fractional = b.digits;
	} else {
		c.digits = divide(a.digits, b.digits);
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
	if (lead) os << num.digits[0];
	return os;
}

std::vector<short> gcd(std::vector<short>& a, std::vector<short>& b) {
	//find their gcd
	std::vector<short> aTmp, bTmp, tmp;
	bool isBreak = false;
	for (int i = 0; i < a.size(); ++i)	aTmp.push_back(a[i]);
	for (int i = 0; i < b.size(); ++i)	bTmp.push_back(b[i]);
	while (isBreak != true){
		//caculate
		tmp = bTmp;
		bTmp = minus(bTmp, mul(bTmp, (divide(aTmp, bTmp))));
		aTmp = tmp;
		//check if  bTmp != 0
		for (long long int i = 0; i < bTmp.size(); i++) {
			if (bTmp[i] != 0)	break;
			else if (i == bTmp.size() - 1)	isBreak = true;
		}
	}
	return tmp;
}