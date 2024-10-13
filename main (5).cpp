#include <iostream>
#include <vector>
#include <stack>
#include <string>

int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<int> stack; // Стек для зберігання операндів

    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Якщо токен - оператор, витягуємо два верхніх операнди
            int b = stack.top(); stack.pop(); // Другий операнд
            int a = stack.top(); stack.pop(); // Перший операнд
            
            int result;
            if (token == "+") {
                result = a + b;
            } else if (token == "-") {
                result = a - b;
            } else if (token == "*") {
                result = a * b;
            } else if (token == "/") {
                // Для ділення за правилами RPN
                result = a / b; // В C++ при діленні цілого числа результат автоматично округлюється вниз
            }
            stack.push(result); // Додаємо результат назад у стек
        } else {
            // Якщо токен - число, додаємо його у стек
            stack.push(std::stoi(token));
        }
    }

    return stack.top(); // Повертаємо результат
}

int main() {
    std::vector<std::string> tokens1 = {"2", "1", "+", "3", "*"};
    std::cout << "Output: " << evalRPN(tokens1) << std::endl; // повертає 9

    std::vector<std::string> tokens2 = {"4", "13", "5", "/", "+"};
    std::cout << "Output: " << evalRPN(tokens2) << std::endl; // повертає 6

    std::vector<std::string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << "Output: " << evalRPN(tokens3) << std::endl; // повертає 22

    return 0;
}
