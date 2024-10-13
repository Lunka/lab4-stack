#include <iostream>
#include <stack>
#include <string>
#include <cctype>

std::string decodeString(const std::string& s) {
    std::stack<int> countStack;  // Стек для зберігання чисел
    std::stack<std::string> stringStack;  // Стек для зберігання рядків
    std::string currentString; // Поточний рядок
    int k = 0; // Поточне число

    for (char ch : s) {
        if (isdigit(ch)) {
            // Якщо символ - цифра, оновлюємо k
            k = k * 10 + (ch - '0'); // Обробляємо кілька цифр
        } else if (ch == '[') {
            // Якщо символ - '[', зберігаємо поточний рядок і число
            countStack.push(k);
            stringStack.push(currentString);
            k = 0; // Скидаємо k для наступного числа
            currentString.clear(); // Очищуємо поточний рядок
        } else if (ch == ']') {
            // Якщо символ - ']', закриваємо один з наборів
            std::string decodedString = stringStack.top(); 
            stringStack.pop();
            int repeatCount = countStack.top(); 
            countStack.pop();
            // Повторюємо currentString repeatCount разів та додаємо до decodedString
            for (int i = 0; i < repeatCount; ++i) {
                decodedString += currentString;
            }
            currentString = decodedString; // Оновлюємо currentString
        } else {
            // Якщо це звичайний символ, додаємо його до поточного рядка
            currentString += ch;
        }
    }

    return currentString; // Повертаємо декодований рядок
}

int main() {
    std::string input1 = "3[a]2[bc]";
    std::cout << "Output: " << decodeString(input1) << std::endl; // повертає "aaabcbc"

    std::string input2 = "3[a2[c]]";
    std::cout << "Output: " << decodeString(input2) << std::endl; // повертає "accaccacc"

    std::string input3 = "2[abc]3[cd]ef";
    std::cout << "Output: " << decodeString(input3) << std::endl; // повертає "abcabccdcdcdef"

    return 0;
}
