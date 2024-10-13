#include <iostream>
#include <stack>
#include <limits>

class MinStack {
private:
    std::stack<int> mainStack;   // Основний стек для зберігання значень
    std::stack<int> minStack;    // Стек для зберігання мінімальних значень

public:
    /** Ініціалізує об’єкт стека. */
    MinStack() {}

    /** Переміщує елемент val у стек. */
    void push(int val) {
        mainStack.push(val); // Додаємо значення в основний стек
        // Додаємо значення в стек мінімумів, якщо це новий мінімум
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    /** Видаляє елемент у верхній частині стека. */
    void pop() {
        // Перевіряємо, чи видаляється мінімум
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop(); // Видаляємо елемент з основного стека
    }

    /** Отримує верхній елемент стека. */
    int top() {
        return mainStack.top(); // Повертаємо верхній елемент основного стека
    }

    /** Отримує мінімальний елемент у стеку. */
    int getMin() {
        return minStack.top(); // Повертаємо верхній елемент стека мінімумів
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // повертає -3
    minStack.pop();
    std::cout << "Top: " << minStack.top() << std::endl; // повертає 0
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // повертає -2

    return 0;
}
