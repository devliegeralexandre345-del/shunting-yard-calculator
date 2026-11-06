#include "shunting_yard.h"
#include <cctype>
#include <sstream>

std::vector<std::string> ShuntingYard::infixToPostfix(const std::string& expression) {
    std::stack<char> operators;
    std::queue<std::string> output;
    
    // Tokenisation de l'expression
    std::vector<std::string> tokens;
    tokenize(expression, tokens);
    
    for (const auto& token : tokens) {
        if (std::isdigit(token[0]) || (token[0] == '.' && token.length() > 1)) {
            output.push(token);
        } else if (isOperator(token[0])) {
            while (!operators.empty() && operators.top() != '(' \
                   && getPrecedence(operators.top()) >= getPrecedence(token[0]) \
                   && isLeftAssociative(token[0])) {
                output.push(std::string(1, operators.top()));
                operators.pop();
            }
            operators.push(token[0]);
        } else if (token == "(") {
            operators.push('(');
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != '(') {
                output.push(std::string(1, operators.top()));
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // Retirer le (
        } else {
            throw std::invalid_argument("Token inconnu: " + token);
        }
    }
    
    while (!operators.empty()) {
        output.push(std::string(1, operators.top()));
        operators.pop();
    }
    
    // Conversion de la queue en vector
    std::vector<std::string> result;
    while (!output.empty()) {
        result.push_back(output.front());
        output.pop();
    }
    
    return result;
}

void ShuntingYard::tokenize(const std::string& expression, std::vector<std::string>& tokens) {
    for (size_t i = 0; i < expression.length();) {
        if (std::isspace(expression[i])) {
            ++i;
            continue;
        }
        
        if (isOperator(expression[i]) || expression[i] == '(' || expression[i] == ')') {
            tokens.push_back(std::string(1, expression[i]));
            ++i;
        } else if (std::isdigit(expression[i])) {
            std::string number;
            while (i < expression.length() && \
                   (std::isdigit(expression[i]) || expression[i] == '.')) {
                number += expression[i];
                ++i;
            }
            tokens.push_back(number);
        } else {
            throw std::invalid_argument("Caractère invalide: " + std::string(1, expression[i]));
        }
    }
}

bool ShuntingYard::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int ShuntingYard::getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

bool ShuntingYard::isLeftAssociative(char op) {
    return op != '^'; // Puissance est droite-associative
}