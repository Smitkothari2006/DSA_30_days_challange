/*
Problem: Check if a Binary Tree is a Binary Search Tree (BST)

You are given the root of a binary tree. Your task is to determine whether the tree is a valid Binary Search Tree (BST). A binary search tree is defined as a tree where:
- Every node’s left subtree contains only nodes with values less than the node’s value.
- Every node’s right subtree contains only nodes with values greater than the node’s value.
- Both the left and right subtrees must also be binary search trees.

Input:
- A binary tree represented by its root node.
- Use -1 to represent null in level-order input.

Output:
- Return true if the binary tree is a valid BST, otherwise return false.

Constraints:
- The number of nodes in the binary tree is in the range [1, 10^4].
- The node values are in the range [-10^5, 10^5].

Example Test Cases:
Input: [2, 1, 3]
Output: true

Input: [5, 1, 4, -1, -1, 3, 6]
Output: false

Input: [10, 5, 15, -1, -1, 6, 20]
Output: false
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <climits>
using namespace std;

// Tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build binary tree from level-order input
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Helper function to validate BST
bool isValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;

    return isValidBSTHelper(node->left, minVal, node->val) &&
           isValidBSTHelper(node->right, node->val, maxVal);
}

// Main function to check if a tree is a valid BST
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    cout << "Enter tree nodes in level-order (-1 for null): ";
    vector<int> nodes;
    int x;
    while (cin >> x) {
        nodes.push_back(x);
        if (cin.peek() == '\n') break;
    }

    TreeNode* root = buildTree(nodes);
    bool result = isValidBST(root);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
