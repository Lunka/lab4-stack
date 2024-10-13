#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> inputStack;   // Стек для додавання елементів
    std::stack<int> outputStack;  // Стек для видалення елементів

    void transferInputToOutput() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    /** Ініціалізує чергу. */
    MyQueue() {}

    /** Переміщує елемент x у кінець черги. */
    void push(int x) {
        inputStack.push(x); // Додаємо елемент у inputStack
    }

    /** Вилучає елемент з початку черги та повертає його. */
    int pop() {
        if (outputStack.empty()) {
            transferInputToOutput(); // Переміщуємо елементи з inputStack у outputStack
        }
        int front = outputStack.top(); // Отримуємо верхній елемент outputStack
        outputStack.pop(); // Видаляємо його з outputStack
        return front; // Повертаємо видалений елемент
    }

    /** Повертає елемент на початку черги. */
    int peek() {
        if (outputStack.empty()) {
            transferInputToOutput(); // Переміщуємо елементи, якщо outputStack порожній
        }
        return outputStack.top(); // Повертаємо верхній елемент outputStack
    }

    /** Повертає true, якщо черга порожня. */
    bool empty() {
        return inputStack.empty() && outputStack.empty(); // Черга порожня, якщо обидва стеки порожні
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2]

    std::cout << "Peek: " << myQueue.peek() << std::endl; // повертає 1
    std::cout << "Pop: " << myQueue.pop() << std::endl;   // повертає 1, queue is [2]
    std::cout << "Empty: " << std::boolalpha << myQueue.empty() << std::endl; // повертає false

    return 0;
}
