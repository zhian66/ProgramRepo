#ifndef _BIG_NUMBER_
#define _BIG_NUMBER_
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>

class BigNumber {
public:
	BigNumber();
	BigNumber(std::string);
	BigNumber(int nr);
	BigNumber(double n);
	BigNumber(const BigNumber& a);

	//BigNumber operator+(const BigNumber&);
	//BigNumber operator-(BigNumber);
	//BigNumber operator*(BigNumber);
	//BigNumber operator/(BigNumber);
	BigNumber operator+();
	BigNumber operator-();

	friend BigNumber Power(BigNumber a, BigNumber b); // a^b
	friend BigNumber factorial(BigNumber a); // n!
	
	// BigNumber& operator=(const BigNumber &);
	friend std::ostream& operator<<(std::ostream& os, const BigNumber &);
	// istream& operator>>(ostream& os);

	friend bool operator<(const BigNumber& a, const BigNumber& b);
	friend bool operator>(const BigNumber& a, const BigNumber& b);
	friend bool operator<=(const BigNumber& a, const BigNumber& b);
	friend bool operator<=(const BigNumber& a, const BigNumber& b);
	friend bool operator==(const BigNumber& a, const BigNumber& b);
	friend BigNumber operator+(const BigNumber& a, const BigNumber& b);
	friend BigNumber operator-(const BigNumber& a, const BigNumber& b);
	friend BigNumber operator*(const BigNumber& a, const BigNumber& b);
	friend BigNumber operator/(const BigNumber& a, const BigNumber& b);

private:
	//std::string dividend;  // if isDec == ture, store integer part
	//std::string divisor;   // if isDec == ture, store fractional part
	std::vector<short> digits;
	std::vector<short> fractional;
	std::vector<short> remainder;
	bool isNeg;
	bool isDec;

	friend std::string add(std::string, std::string);
	friend int Length(const BigNumber& a);
	friend bool geq(const std::vector<short>& a, const std::vector<short>& b);
	friend std::vector<short> add(const std::vector<short>& a, const std::vector<short>& b);
	friend std::vector<short> minus(const std::vector<short>& a, const std::vector<short>& b);
	friend std::vector<short> mul(const std::vector<short>& a, const std::vector<short>& b);
	friend std::vector<short> divide(const std::vector<short>& a, const std::vector<short>& b);

	friend void reductionOfFraction(std::vector<short>& a, std::vector<short>& b);
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