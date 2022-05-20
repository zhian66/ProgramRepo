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
	bool Invaild = 0;

	BigNumber operator+();
	BigNumber operator-();

	
	BigNumber& operator=(BigNumber);
	std::string to_string();
	void Int();
	void Dec();

	friend std::ostream& operator<<(std::ostream& os, const BigNumber &);
	friend std::ostream& operator>>(std::ostream& os, const BigNumber &);

	friend bool operator<(const BigNumber& a, const BigNumber& b);
	friend bool operator>(const BigNumber& a, const BigNumber& b);
	friend bool operator<=(const BigNumber& a, const BigNumber& b);
	friend bool operator<=(const BigNumber& a, const BigNumber& b);
	friend bool operator==(const BigNumber& a, const BigNumber& b);
	friend BigNumber operator+(const BigNumber& a, const BigNumber& b);
	friend BigNumber operator-(const BigNumber& a, const BigNumber& b);
	friend BigNumber operator*(const BigNumber& a, const BigNumber& b);
	friend BigNumber operator/(const BigNumber& a, const BigNumber& b);
	
	friend BigNumber Power(const BigNumber& a, const BigNumber& b);
	friend BigNumber factorial(BigNumber a); // n!
	
private:
	std::vector<short> digits;
	std::vector<short> fractional;
	bool isNeg;
	bool isDec;

	friend std::vector<short> add(const std::vector<short>& a, const std::vector<short>& b);
	friend std::vector<short> minus(const std::vector<short>& a, const std::vector<short>& b);
	friend std::vector<short> mul(const std::vector<short>& a, const std::vector<short>& b);
	friend std::vector<short> divide(const std::vector<short>& a, const std::vector<short>& b);
	friend std::vector<short> gcd(const std::vector<short>& a, const std::vector<short>& b);
	friend std::vector<short> lcm(const std::vector<short>& a, const std::vector<short>& b);
	friend void Dec2Fra(const std::string& decimal, std::vector<short>& a, std::vector<short>& b);
	friend void reduction(std::vector<short>& a, std::vector<short>& b);
};


#endif
