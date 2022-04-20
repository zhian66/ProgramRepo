#ifndef _BIG_NUMBER_
#define _BIG_NUMBER_
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>

class BigNumber {
private:
	std::string dividend;  // if isDec == ture, store integer part
	std::string divisor;   // if isDec == ture, store fractional part
	bool isNeg;
	bool isDec;
public:
	BigNumber();
	BigNumber(std::string);

	BigNumber operator+(BigNumber);
	BigNumber operator+();
	BigNumber operator-(BigNumber);
	BigNumber operator-();
	BigNumber operator*(BigNumber);
	BigNumber operator/(BigNumber);
	BigNumber power(BigNumber a, BigNumber b); // a^b
	BigNumber factorial(BigNumber n); // n!
	
	
	// BigNumber& operator=(const BigNumber &);
	// ostream& operator<<(const BigNumber&);
	// istream& operator>>(const BigNumber&);
};


#endif

#ifndef _Integer_
#define _Integer_
class Integer : public BigNumber {
public:
	Integer(); // set number = 0 and sign = 0
	Integer(std::string); // set number and sign
};
#endif

#ifndef _Decimal_
#define _Decimal_
class Decimal : public BigNumber {
public:
	Decimal();
	Decimal(std::string);
};
#endif