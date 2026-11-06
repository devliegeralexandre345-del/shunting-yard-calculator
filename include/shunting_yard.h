#pragma once
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <stdexcept>

class ShuntingYard {
public:
    static std::vector<std::string> infixToPostfix(const std::string& expression);
private:
    static bool isOperator(char c);
    static int getPrecedence(char op);
    static bool isLeftAssociative(char op);
    static void tokenize(const std::string& expression, std::vector<std::string>& tokens);
};