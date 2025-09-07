/*
    Lowest Common Ancestor (LCA) in a Binary Tree

    You are given a binary tree and two distinct nodes within the tree. 
    Your task is to find the lowest common ancestor (LCA) of these two nodes. 
    The LCA of two nodes p and q is defined as the lowest node in the tree 
    that has both p and q as descendants (where we allow a node to be a descendant of itself).

    Input:
    A binary tree represented as a series of nodes where each node has references to its left and right child.
    Two distinct nodes p and q from the tree.

    Output:
    Return the node that is the lowest common ancestor (LCA) of p and q.
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build binary tree from level order input
TreeNode* buildTree(const vector<string>& nodes, unordered_map<int, TreeNode*>& nodeMap) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    nodeMap[root->val] = root;
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != "null") {
            TreeNode* leftNode = new TreeNode(stoi(nodes[i]));
            current->left = leftNode;
            q.push(leftNode);
            nodeMap[leftNode->val] = leftNode;
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "null") {
            TreeNode* rightNode = new TreeNode(stoi(nodes[i]));
            current->right = rightNode;
            q.push(rightNode);
            nodeMap[rightNode->val] = rightNode;
        }
        i++;
    }

    return root;
}

// Recursive function to find LCA
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
}

int main() {
    string line;
    cout << "Enter tree nodes in level order (use 'null' for missing nodes *USE SPACEBAR TO ADD MULTIPLE NUMBERS*):" << endl;
    getline(cin, line);

    istringstream iss(line);
    vector<string> nodes;
    string nodeVal;

    while (iss >> nodeVal) {
        nodes.push_back(nodeVal);
    }

    unordered_map<int, TreeNode*> nodeMap;
    TreeNode* root = buildTree(nodes, nodeMap);

    int pVal, qVal;
    cout << "Enter value of node p: ";
    cin >> pVal;
    cout << "Enter value of node q: ";
    cin >> qVal;

    TreeNode* p = nodeMap[pVal];
    TreeNode* q = nodeMap[qVal];

    if (!p || !q) {
        cout << "Invalid node values. One or both nodes not found in the tree." << endl;
        return 1;
    }

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    else
        cout << "No common ancestor found." << endl;

    return 0;
}
