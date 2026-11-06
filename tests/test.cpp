#include <iostream>
#include <cassert>
#include <string>
#include "shunting_yard.h"
#include "calculator.h"

void testShuntingYard() {
    // Test simple addition
    auto result = ShuntingYard::infixToPostfix("1 + 2");
    assert(result.size() == 3);
    assert(result[0] == "1");
    assert(result[1] == "2");
    assert(result[2] == "+");
    
    // Test multiplication et addition
    result = ShuntingYard::infixToPostfix("1 + 2 * 3");
    assert(result.size() == 5);
    assert(result[0] == "1");
    assert(result[1] == "2");
    assert(result[2] == "3");
    assert(result[3] == "*");
    assert(result[4] == "+");
    
    // Test parenthèses
    result = ShuntingYard::infixToPostfix("(1 + 2) * 3");
    assert(result.size() == 5);
    assert(result[0] == "1");
    assert(result[1] == "2");
    assert(result[2] == "+");
    assert(result[3] == "3");
    assert(result[4] == "*");
    
    std::cout << "Tests Shunting Yard réussis!\n";
}

void testCalculator() {
    // Test simple addition
    auto postfix = ShuntingYard::infixToPostfix("1 + 2");
    double result = Calculator::evaluate(postfix);
    assert(result == 3.0);
    
    // Test multiplication et division
    postfix = ShuntingYard::infixToPostfix("6 / 2 * 3");
    result = Calculator::evaluate(postfix);
    assert(result == 9.0);
    
    // Test puissance
    postfix = ShuntingYard::infixToPostfix("2 ^ 3 + 1");
    result = Calculator::evaluate(postfix);
    assert(result == 9.0);
    
    std::cout << "Tests Calculateur réussis!\n";
}

int main() {
    testShuntingYard();
    testCalculator();
    std::cout << "Tous les tests passés avec succès !\n";
    return 0;
}