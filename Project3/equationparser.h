#ifndef EQUATIONPARSER_H
#define EQUATIONPARSER_H

#include <vector>
#include <string>
#include <stack>
#include <QDebug>
using namespace std;

class EquationParser
{

public:
    EquationParser();


private:
    vector<string> postfix;
    vector<pair<string, double>> varList;

    int priority(char op);
    int calculate(const string& input);
};



#endif // EQUATIONPARSER_H
