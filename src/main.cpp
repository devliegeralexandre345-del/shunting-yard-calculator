#include <iostream>
#include <string>
#include "shunting_yard.h"
#include "calculator.h"

int main() {
    std::cout << "Shunting Yard Calculator - Entrez 'quit' pour quitter\n";
    
    while (true) {
        std::cout << ">> ";
        std::string input;
        std::getline(std::cin, input);
        
        if (input == "quit") break;
        
        try {
            auto postfix = ShuntingYard::infixToPostfix(input);
            double result = Calculator::evaluate(postfix);
            std::cout << "= " << result << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Erreur: " << e.what() << "\n";
        }
    }
    
    return 0;
}