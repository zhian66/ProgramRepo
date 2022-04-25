#include <iostream>
#include <string>
using namespace std;

string divideLargeNumber(string number, int divisor) {
    // to store the result
    string result;
    int index = 0;
    // extracting the part that is greater than the given divisor
    int dividend = number[index] - '0';
    while (dividend < divisor) {
        dividend = dividend * 10 + (number[++index] - '0');
    }
    // iterating until all digits participate in the division
    while (number.size() > index) {
        result += (dividend / divisor) + '0';
        // adding the next digit to the dividend
        dividend = (dividend % divisor) * 10 + number[++index] - '0';
    }
    if (result.length() == 0) {
        return "0";
    }
    return result;
}
int main() {
    string large_number = "12345678901234567890";
    int divisor = 75;
    cout << divideLargeNumber(large_number, divisor) << endl;
    return 0;
}