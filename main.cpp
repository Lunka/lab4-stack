#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::stack<char> stk;
    std::unordered_map<char, char> brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        // Якщо це закрита дужка
        if (brackets.count(c)) {
            // Перевіряємо, чи стек не пустий і верхня дужка у стеці відповідає закритій дужці
            if (stk.empty() || stk.top() != brackets[c]) {
                return false; // Не валідна дужка
            }
            stk.pop(); // Відкидаємо відкриту дужку
        } else {
            // Додаємо відкриту дужку у стек
            stk.push(c);
        }
    }
    
    // Якщо стек пустий, значить всі дужки закриті
    return stk.empty();
}

int main() {
    std::string s;
    std::cout << "Enter a string of parentheses: ";
    std::cin >> s;

    if (isValid(s)) {
        std::cout << "Output: true" << std::endl;
    } else {
        std::cout << "Output: false" << std::endl;
    }

    return 0;
}
