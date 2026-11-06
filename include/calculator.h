#pragma once
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <stdexcept>

class Calculator {
public:
    static double evaluate(const std::vector<std::string>& postfix);
private:
    static bool isOperator(const std::string& token);
    static double applyOperation(double a, double b, const std::string& op);
};