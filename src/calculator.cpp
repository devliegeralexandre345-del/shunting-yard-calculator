#include "calculator.h"
#include <cmath>
#include <stdexcept>

double Calculator::evaluate(const std::vector<std::string>& postfix) {
    if (postfix.empty()) return 0.0;
    
    std::stack<double> stack;
    
    for (const auto& token : postfix) {
        if (!isOperator(token)) {
            try {
                double value = std::stod(token);
                stack.push(value);
            } catch (const std::exception&) {
                throw std::invalid_argument("Valeur invalide: " + token);
            }
        } else {
            if (stack.size() < 2) {
                throw std::runtime_error("Expression mal formée");
            }
            
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            
            double result = applyOperation(a, b, token);
            stack.push(result);
        }
    }
    
    if (stack.size() != 1) {
        throw std::runtime_error("Expression mal formée");
    }
    
    return stack.top();
}

bool Calculator::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}

double Calculator::applyOperation(double a, double b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0.0) throw std::runtime_error("Division par zéro");
        return a / b;
    }
    if (op == "^") return std::pow(a, b);
    
    throw std::invalid_argument("Opérateur inconnu: " + op);
}