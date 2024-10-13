#include <iostream>
#include <stack>
#include <string>

int longestValidParentheses(const std::string& s) {
    std::stack<int> stack;
    stack.push(-1); // Ініціалізуємо стек, щоб зберігати базу для обчислення довжини
    int maxLength = 0; // Змінна для зберігання максимальної довжини

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            // Додаємо індекс відкритої дужки у стек
            stack.push(i);
        } else {
            // Коли натрапляємо на закриту дужку
            stack.pop(); // Витягуємо верхній індекс
            if (stack.empty()) {
                // Якщо стек порожній, додаємо поточний індекс
                stack.push(i);
            } else {
                // Обчислюємо довжину дійсних дужок
                maxLength = std::max(maxLength, i - stack.top());
            }
        }
    }

    return maxLength; // Повертаємо максимальну довжину
}

int main() {
    std::string input1 = "(()";
    std::cout << "Output: " << longestValidParentheses(input1) << std::endl; // повертає 2

    std::string input2 = ")()())";
    std::cout << "Output: " << longestValidParentheses(input2) << std::endl; // повертає 4

    std::string input3 = "";
    std::cout << "Output: " << longestValidParentheses(input3) << std::endl; // повертає 0

    return 0;
}
