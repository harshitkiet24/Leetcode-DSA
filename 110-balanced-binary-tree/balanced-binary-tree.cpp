/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, int& y) {
        if (root == nullptr) {
            return 0;
        }
        int left = height(root->left, y);
        int right = height(root->right, y);

        if (abs(left - right) > 1) {
            y = 0;
        }
        int ans = max(left, right) + 1;
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int y = 1;
        height(root, y);
        return y;
    }
};