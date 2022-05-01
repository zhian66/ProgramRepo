#include "BigNumber.h"
#include <vector>
#include <sstream>
#define ERROR_MSG "Invaild Number"

void printError() {
	std::cout << ERROR_MSG << std::endl;
}
void movezero(std::vector<short>& c) {
	for (int i = c.size() - 1; i > 0; i--) {
		if (c[i] == 0) {
			c.pop_back();
		} else {
			return;
		}
	}
}
bool geq(const std::vector<short>& a, const std::vector<short>& b) {
	if (a.size() > b.size()) return true;
	else if (a.size() < b.size()) return false;
	else {
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a[i] < b[i]) return false;
			else if (a[i] > b[i]) return true;
			
		}
	}
	return true;
}
bool equal(const std::vector<short>& a, const std::vector<short>& b) {
	if (a.size() != b.size()) return false;
	else {
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a[i] != b[i]) {
				return false;
			}
		}
	}
	return true;
}
bool less(const std::vector<short>& a, const std::vector<short>& b) {
	if (a.size() < b.size()) return true;
	else if (a.size() > b.size()) return false;
	else {
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a[i] > b[i]) return false;
			else if (a[i] < b[i]) return true;
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
	movezero(c);
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
	movezero(c);
	return c;
}
std::vector<short> mul(const std::vector<short>& a, const std::vector<short>& b) {
	std::vector<short> c;
	int m = a.size(), n = b.size(), size = m > n ? m : n;
	c.resize(m + n, 0);
	int i = 0, j = 0;
	int carry = 0;
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j)
			c[i + j] += a[i] * b[j];
	}

	for (i = 0; i < m + n - 1; ++i) {
		if (c[i] >= 10) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	movezero(c);
	return c;
}
std::vector<short> divide(const std::vector<short>& a, const std::vector<short>& b) {
	std::vector<short> c(1,0);
	std::vector<short> tmp, aTmp = a, bTmp, t;
	while (geq(aTmp, b)) {
		bTmp = b;
		int i; 
		tmp.clear();
		for (i=0; ; i++) {
			bTmp.insert(bTmp.begin(), 0);
			if (geq(aTmp, bTmp)) tmp.push_back(0);
			else break;
		}
		tmp.push_back(1);
		bTmp = mul(tmp, b);
		for (short j = 9; j > 0;j--) {
			t = mul(bTmp, {j});
			if (geq(aTmp, t)) {
				tmp = mul(tmp, {j});
				c = add(c, tmp);
				aTmp = minus(aTmp, t);
				
			}
		}
	}

	/*
	while (geq(x, b)) {
		t = b;
		for (int i = 0; geq(x, t); i++) {
			x = minus(x, t);
			tmp.clear();
			for (int j = 0; j < i; j++) {
				tmp.push_back(0);
			}

			tmp.push_back(1);
			c = add(c, tmp);
			t.insert(t.begin(), 0);
		}
	}
	*/
	movezero(c);
	return c;
}
std::vector<short> gcd(const std::vector<short>& a, const std::vector<short>& b) {
	//find their gcd
	std::vector<short> aTmp, bTmp, tmp;
	if (a == b) return a;
	if (geq(a,b)) {
		aTmp = a;
		bTmp = b;
	} else {
		aTmp = b;
		bTmp = a;
	}
	bool isBreak = false;
	while (!isBreak) {
		//caculate
		tmp = minus(aTmp, mul(bTmp, (divide(aTmp, bTmp))));
		//check if  bTmp != 0
		if (tmp.size() == 1 && tmp[0] == 0) {
			break;
		}
		aTmp = bTmp;
		bTmp = tmp;
	}
	movezero(bTmp);
	return bTmp;
}
std::vector<short> lcm(const std::vector<short>& a, const std::vector<short>& b) {
	std::vector<short> c_lcm, c_gcd;
	c_gcd = gcd(a, b);
	c_lcm = divide(mul(a, b), c_gcd);
	return c_lcm;
}

std::vector<short> power(const std::vector<short>& a, const std::vector<short>& b) {
	std::vector<short> c = { 1 };
	std::vector<short> times = b;
	while (!(times.size() == 1 && times[0] == 0)) {
		c = mul(c, a);
		times = minus(times, { 1 });
	}
	return c;
}
std::vector<short> sqrt(const std::vector<short>& a) {
	std::vector<short>  aTmp = a, mid, high, low, tmp;
	if (a.size() == 1 && a[0] == 1) {
		return a;
	}
	high = a;
	low = { 0 };
	mid = { 0 };
	while (1) {
		mid = divide(add(low, high), {2});
		aTmp = power(mid, {2});
		if (equal(aTmp, a)) {
			break;
		} else if (geq(aTmp, a)) {
			high = mid;
		} else {
			low = mid;
		}
		if (geq(a, aTmp) && (!equal(a, power(add(mid, { 1 }), { 2 })) && less(a, power(add(mid, { 1 }), { 2 })))) break;
	}
	return mid;
}
std::vector<short> mod(const std::vector<short>& a, const std::vector<short>& b) {
	std::vector<short> c(1, 0);
	std::vector<short> tmp, aTmp = a, bTmp, t;
	while (geq(aTmp, b)) {
		bTmp = b;
		int i;
		tmp.clear();
		for (i = 0; ; i++) {
			bTmp.insert(bTmp.begin(), 0);
			if (geq(aTmp, bTmp)) tmp.push_back(0);
			else break;
		}
		tmp.push_back(1);
		bTmp = mul(tmp, b);
		for (short j = 9; j > 0; j--) {
			t = mul(bTmp, { j });
			if (geq(aTmp, t)) {
				tmp = mul(tmp, { j });
				c = add(c, tmp);
				aTmp = minus(aTmp, t);

			}
		}
	}
	movezero(aTmp);
	return aTmp;
}

void Dec2Fra(const std::string &decimal, std::vector<short> &a, std::vector<short> &b) {
	a.clear();
	b.clear();
	std::string str;
	int size = decimal.size() - 1;
	int len = 0;
	for (int i = size; i >= 0; i--) {
		if (decimal[i] != '0') break;
		len++;
	}
	str = decimal.substr(0, decimal.size()-len);
	size_t found = str.find('.');
	if (found == std::string::npos) str.insert(str.begin(), '.');
	bool dot = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '.') dot = 1;
		if (c > '9' || c < '0') continue;
		a.push_back(c-'0');
		if (dot) b.push_back(0);
	}
	b.push_back(1);
	movezero(a);
	std::reverse(a.begin(), a.end());
}
void reduction(std::vector<short>& a, std::vector<short>& b) {
	// a: Numerator  b: denominator
	if ((a.size() == 1 && a[0] > 1) || a.size() > 1) {
		auto c_gcd = gcd(b, a);
		a = divide(a, c_gcd);
		b = divide(b, c_gcd);
	}
}

BigNumber::BigNumber() {
	isNeg = 0;
	isDec = 0;
	digits = {0};
	fractional = { 1 };
}
BigNumber::BigNumber(std::string input) {
	isNeg = 0;
	if (input[0] == '-') {
		isNeg = 1;
	} 
	size_t found = input.find_last_of(".");
	if (found != std::string::npos) {
		isDec = 1;
		/*
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
		*/
		std::string decimal = "";
		for (int i = 0; i < input.size(); i++) {
			char c = input[i];
			if (c == '-' || c == ' ') {} 
			else {
				decimal += c;
			}
		}
		std::vector<short> remainder;
		Dec2Fra(decimal, digits, fractional);
		reduction(remainder, fractional);
		//digits = add(mul(digits, fractional), remainder);
		//reduction(remainder, fractional);

	} else {
		isDec = 0;
		for (auto c : input) {
			if (c == '-' || c == '.') {} 
			else if (c == ' ') {} 
			else digits.push_back(c - '0');
		}
		std::reverse(digits.begin(), digits.end());
		fractional = {1};
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
	fractional = { 1 };
}
BigNumber::BigNumber(double n) {
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
	//std::cout << nr << " " << dec << std::endl;
	std::string decimal = std::to_string(dec);
	decimal = decimal.erase(0, decimal.find('.') + 1);
	std::vector<short> remainder;
	fractional = { 1 };
	Dec2Fra(decimal, remainder, fractional);
	reduction(remainder, fractional);
	digits = add(mul(digits, fractional), remainder);
}
BigNumber::BigNumber(const BigNumber& a) {
	//dividend = a.dividend;
	Invaild = a.Invaild;
	isNeg = a.isNeg;
	isDec = a.isDec;
	digits = a.digits;
	fractional = a.fractional;
}

BigNumber& BigNumber::operator=(BigNumber a) {
	Invaild = a.Invaild;
	isNeg = a.isNeg;
	isDec = a.isDec;
	digits = a.digits;
	if (a.isDec) fractional = a.fractional;
	else fractional = { 1 };
	return *this;
}

bool operator<(const BigNumber& a, const BigNumber& b) {
	if (a.isNeg && !b.isNeg) return true; // a:- b:+
	else if (!a.isNeg && b.isNeg) return false; // a:+ b:-
	if (equal(a.fractional, b.fractional)) {
		return (less(a.digits, b.digits)) && (!a.isNeg);
	} else {
		auto aTmp = mul(a.digits, b.fractional);
		auto bTmp = mul(b.digits, a.fractional);
		return (less(aTmp, bTmp)) && (!a.isNeg);
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
	if (a.fractional.size() != b.fractional.size()) return false;
	if (equal(a.fractional, b.fractional)) {
		if (a.digits.size() != b.digits.size()) return false;
		if (equal(a.digits, b.digits)) return true;
	}
	return false;
}

BigNumber operator+(const BigNumber& a, const BigNumber& b) {
	BigNumber c;
	if (!a.isNeg && !b.isNeg) {
		if (a.isDec || b.isDec) {
			c.isDec = 1;
			if (equal(a.fractional, b.fractional)) {
				c.fractional = a.fractional;
				c.digits = add(a.digits, b.digits);
			} else {
				auto c_gcd = gcd(a.fractional, b.fractional);
				c.fractional = divide(mul(a.fractional, b.fractional), c_gcd);
				c.digits = add(mul(a.digits, c.fractional), mul(b.digits, c_gcd));
				reduction(c.digits, c.fractional);
			}	
		} else {
			c.digits = add(a.digits, b.digits);
			c.fractional = { 1 };
			c.isDec = 0;
			c.isNeg = 0;
		}
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
	if (a == b) {
		c = 0;
		return c;
	}

	if (!a.isNeg && !b.isNeg) {
		// a:+ b:+
		if (a > b) {

			if (a.isDec || b.isDec) {

				c.isDec = 1;
				if (a.fractional == b.fractional) {
					c.fractional = a.fractional;
					c.digits = minus(a.digits, b.digits);
				} else {
					auto c_gcd = gcd(a.fractional, b.fractional);
					c.fractional = divide(mul(a.fractional, b.fractional), c_gcd);
					c.digits = minus(mul(a.digits, divide(b.fractional, c_gcd)), mul(b.digits, divide(a.fractional, c_gcd)));
					reduction(c.digits, c.fractional);
				}
			} else {
				c.digits = minus(a.digits, b.digits);
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
	if (a.isDec || b.isDec) {
		c.isDec = 1;
		c.digits = mul(a.digits, b.digits);
		c.fractional = mul(a.fractional, b.fractional);
		reduction(c.digits, c.fractional);
	} else {
		c.digits = mul(a.digits, b.digits);
	}
	if (a.isNeg || b.isNeg) c.isNeg = 1;
	return c;
}
BigNumber operator/(const BigNumber& a, const BigNumber& b) {
	BigNumber c;
	if ((b.digits.size() == 1) && b.digits[0] == 0) {
		printError();
		c.Invaild = 1;
		return c;
	}
	if (a == b) {
		c = 1;
	} else {
		if (a.isDec || b.isDec) {
			c.isDec = 1;
			c.digits = mul(a.digits, b.fractional);
			c.fractional = mul(a.fractional, b.digits);
			reduction(c.digits, c.fractional);
		} else {
			c.digits = divide(a.digits, b.digits);
		}
	}
	if (a.isNeg || b.isNeg) c.isNeg = 1;
	if (a.isDec || b.isDec) c.isDec = 1;
	return c;
}

BigNumber BigNumber::operator-() {
	isNeg = !isNeg;
	return *this;
}

BigNumber factorial(BigNumber a) {
	BigNumber c;
	reduction(a.digits, a.fractional);
	if (!(a.fractional.size() == 1 && a.fractional[0] == 1)) {
		c.Invaild = 1;
		printError();
		return c;
	} else if (a.isNeg) {
		c.Invaild = 1;
		printError();
		return c;
	}
	c = 1;
	while (!(a.digits.size() == 1 && a.digits[0] == 0)) {
		c.digits = mul(c.digits, a.digits);
		a.digits = minus(a.digits, {1});
	}
	if (a.isDec) c.isDec = 1;
	return c;
}

void Sqrt(const std::vector<short>& a, std::vector<short>& up, std::vector<short>& down) {
	if (a.size() == 1 && a[0] == 1) {
		up = { 1 };
		down = { 0 };
		return;
	} else if (a.size() == 1 && a[0] == 0) {
		up = { 0 };
		down = { 1 };
		return;
	}
	std::string result = "";
	std::vector<short> aTmp(200, 0), cTmp, b(1, 0), bTmp, tmp;
	int size = a.size();
	bool first = 1;
	for (int i = 0; i < a.size(); i++) aTmp.push_back(a[i]);
	for (int i = aTmp.size() - 1; i >= 0;) {
		if (size % 2 == 1 && first) {
			first = 0;
			cTmp.insert(cTmp.begin(), aTmp[i]);
			i--;
		} else {
			cTmp.insert(cTmp.begin(), aTmp[i]);
			cTmp.insert(cTmp.begin(), aTmp[i - 1]);
			i -= 2;
		}
		movezero(cTmp);
		short k = 0;
		for (short j = 0; j <= 10; j++) {
			tmp = mul(add(mul(b, { 0,1 }), { j }), { j });
			if (equal(tmp, cTmp)) {
				k = j;
			} 
			if (geq(tmp, cTmp)) {
				tmp = mul(add(mul(b, { 0,1 }), { k }), { k });
				cTmp = minus(cTmp, tmp);
				b = add(add(mul(b, { 0, 1 }), { k }), {k});
				result += std::to_string(k);
				break;
			}
			k = j;
		}
	}
	size = (size % 2 == 0) ? size / 2 : size / 2 + 1;
	result.insert(result.begin() + size, '.');
	Dec2Fra(result, up, down);
}


BigNumber Power(const BigNumber& a, const BigNumber& b) {
	BigNumber c = a, tmp, bTmp = b;
	int times;
	if (a.isDec || b.isDec) {
		c.isDec = 1;
	}
	if (!b.isNeg) {
		reduction(bTmp.digits, bTmp.fractional);
		if (bTmp.digits.size() == 1 && bTmp.digits[0] == 0) {
			c.digits = { 1 };
			c.fractional = { 1 };
			return c;
		}
		if (b.isDec) { 
			if (!(bTmp.fractional.size() == 1 && bTmp.fractional[0] == 2) && !(bTmp.fractional.size() == 1 && bTmp.fractional[0] == 1)) {
				c.Invaild = 1;
				printError();
				return c;
			}
			if (a.isNeg) {	// decimal can't sqrt
				c.Invaild = 1;
				printError();
				return c;
			}
			if (a.isDec) {	// (decimal) ^ decimal
				if (bTmp.fractional.size() == 1 && bTmp.fractional[0] == 2) {  // sqrt
					BigNumber up, down;
					tmp.digits = power(a.digits, b.digits);
					tmp.fractional = power(a.fractional, b.digits);
					Sqrt(tmp.digits, up.digits, up.fractional);
					if (bTmp.fractional.size() == 1 && bTmp.fractional[0] == 2) Sqrt(tmp.fractional, down.digits, down.fractional);
					c.digits = mul(up.digits, down.fractional);
					c.fractional = mul(up.fractional, down.digits);
				} else {
					c.digits = power(a.digits, b.digits);
					c.fractional = power(a.fractional, b.digits);
				}
			} else {		// (int) ^ decimal
				tmp.digits = power(a.digits, b.digits);
				Sqrt(a.digits, c.digits, c.fractional);
			}
		} else { // a^(int)
			std::vector<short> remainder = mod(b.digits, { 2 });
			if (a.isNeg) {
				if ((remainder.size() == 1 && remainder[0] == 0)) {
					c.isNeg = 0;
				} else {
					c.isNeg = 1;
				}
			}
			if (a.isDec) { // (decimal) ^ Int
				c.digits = power(a.digits, b.digits);
				c.fractional = power(a.fractional, b.digits);
			} else { // (Int) ^ Int
				c.digits = power(a.digits, b.digits);
			}
		}
		/*
		std::cout << "up.d:\n";
		for (int i = up.digits.size() - 1; i >= 0; i--) {
			std::cout << up.digits[i];
		}
		std::cout << "\n";

		std::cout << "up.f:\n";
		for (int i = up.fractional.size() - 1; i >= 0; i--) {
			std::cout << up.fractional[i];
		}
		std::cout << "\n";

		std::cout << "down.d:\n";
		for (int i = down.digits.size() - 1; i >= 0; i--) {
			std::cout << down.digits[i];
		}
		std::cout << "\n";

		std::cout << "down.f:\n";
		for (int i = down.fractional.size() - 1; i >= 0; i--) {
			std::cout << down.fractional[i];
		}
		std::cout << "\n";
		*/

	} else {
		tmp = b;
		tmp.isNeg = 0;
		c = 1 / Power(a, tmp);
	}
	return c;
}



std::ostream& operator<<(std::ostream& os, const BigNumber & num) {
	if (num.isNeg) os << '-';
	if (num.isDec) {
		std::string result = "";
		std::vector<short> ten = {0, 1}; // 10
		std::vector<short> tmp, rTmp = num.digits, fTmp = num.fractional, dTmp;
		dTmp = divide(num.digits, num.fractional);
		int len = 0;
		while (len < 100 && !(rTmp.size() == 1 && rTmp[0] == 0)) {
			rTmp = mul(rTmp, ten);
			tmp = divide(rTmp, fTmp);
			rTmp = minus(rTmp, mul(fTmp, tmp));
			result += std::to_string(tmp[0]);
			len++;
		}
		for (int i = len; i < 100; i++) {
			result += '0';
		}
		for (int i = dTmp.size() - 1; i >= 0; i--) {
			os << dTmp[i];
		}
		os << "." << result;
	} else {
		for (int i = num.digits.size() - 1; i >= 0; i--) {
			os << num.digits[i];
		}
	}
	return os;
}

std::ostream& operator>>(std::ostream& os, const BigNumber & num) {
	os >> num.isNeg;
	os >> num.isDec;
	for (auto &n : num.digits) {
		os >> n;
	}
	for (auto& n : num.fractional) {
		os >> n;
	}
	return os;
}


std::string BigNumber::to_string() {
	std::string result = "";
	std::stringstream ss;
	if (this->isNeg) ss << '-';
	if (this->isDec) {
		std::string result = "";
		std::vector<short> ten = { 0, 1 }; // 10
		std::vector<short> tmp, rTmp = this->digits, fTmp = this->fractional, dTmp;
		dTmp = divide(this->digits, this->fractional);
		int len = 0;
		while (len < 100 && !(rTmp.size() == 1 && rTmp[0] == 0)) {
			rTmp = mul(rTmp, ten);
			tmp = divide(rTmp, fTmp);
			rTmp = minus(rTmp, mul(fTmp, tmp));
			result += std::to_string(tmp[0]);
			len++;
		}
		for (int i = len; i < 100; i++) {
			result += '0';
		}
		for (int i = dTmp.size() - 1; i >= 0; i--) {
			ss << dTmp[i];
		}
		ss << "." << result;
	} else {
		for (int i = this->digits.size() - 1; i >= 0; i--) {
			ss << this->digits[i];
		}
	}

	ss >> result;
	return result;
}

void BigNumber::Int() {
	isDec = 0;
	digits = divide(digits, fractional);
}
void BigNumber::Dec() {
	isDec = 1;
}

/*
* 
BigNumber up, down, bTmp, sqr, sqr2;
sqr.digits = c.digits;
		sqr2.digits = add(sqr.digits, sqr.digits);
		bTmp.digits = minus(a.digits, power(c.digits, {2}));
		if (!equal(bTmp.digits, { 0 })) {
			up.isDec = 1;
			for (int i = 0; i < 50; i++) {
				if (equal(sqr2.fractional, up.fractional)) {
					up.digits = add(up.digits, sqr2.digits);
				} else {
					up.digits = add(mul(sqr2.digits, up.fractional), up.digits);
					reduction(up.digits, up.fractional);
				}
				tmp.digits = up.digits;
				tmp.fractional = up.fractional;
				up.fractional = mul(bTmp.fractional, tmp.digits);
				up.digits = mul(bTmp.digits, tmp.fractional);
				reduction(up.digits, up.fractional);
			}
			if (equal(sqr.fractional, up.fractional)) {
				up.digits = add(up.digits, sqr.digits);
			} else {
				up.digits = add(mul(sqr.digits, up.fractional), up.digits);
				reduction(up.digits, up.fractional);
			}
			c.digits = up.digits;
			c.fractional = up.fractional;
		}

*/