#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) {
        return; // Якщо вузол пустий, нічого не робимо
    }
    
    inorderTraversal(root->left, result); // Рекурсивно обходимо ліве піддерево
    result.push_back(root->val);          // Додаємо значення кореня
    inorderTraversal(root->right, result); // Рекурсивно обходимо праве піддерево
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    inorderTraversal(root, result); // Викликаємо допоміжну функцію
    return result;
}
int main() {
    // Створення бінарного дерева
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);

    // Виклик функції обхід у порядку
    std::vector<int> result = inorderTraversal(root);
    
    // Виведення результату
    std::cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    // Очищення пам'яті
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

