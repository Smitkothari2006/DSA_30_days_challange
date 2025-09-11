#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Check if a Binary Tree is Symmetric

You are given the root of a binary tree. Your task is to determine whether the tree is symmetric. 
A binary tree is symmetric if the left and right subtrees are mirror images of each other.

Input:
The root of the binary tree.

Output:
Return true if the binary tree is symmetric, otherwise return false.

Examples:
Example 1
Input: [1, 2, 2, 3, 4, 4, 3]
Output: true
Explanation: 
This binary tree is symmetric as the left and right subtrees are mirror images of each other.

Constraints:
The number of nodes in the tree is between 1 and 10^4
The value of each node is between −100 and 100.

Test Cases:
Input: [1, 2, 2, 3, 4, 4, 3]
Output: true
Input: [1, 2, 2, null, 3, null, 3]
Output: false
Input: [1]
Output: true
Input: []
Output: true
Input: [1, 2, 2, 3, null, null, 3]
Output: false

Edge Cases:
An empty tree is symmetric by definition. Return true.
A single-node tree is symmetric since there are no children to compare. Return true.
If there is one child but not the other, the tree is not symmetric. Return false.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if two trees are mirrors of each other
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val)
        && isMirror(t1->left, t2->right)
        && isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true; // Empty tree is symmetric
    return isMirror(root->left, root->right);
}

// Function to build tree from vector input (level order) where -1 represents null
// (Since values are between -100 and 100, we can safely use -1 for null)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nodes[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i >= (int)nodes.size()) break;

        // Right child
        if (nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    cout << "Enter the number of nodes in the tree: ";
    int n; 
    cin >> n;

    cout << "Enter the nodes in level order (use -1 for null):\n";
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);
    bool result = isSymmetric(root);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
