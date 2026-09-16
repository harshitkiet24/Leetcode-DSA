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
    bool check(TreeNode* root, long long low, long long high) {
        if (root == nullptr) {
            return true;
        }
        if (low >= root->val || high <= root->val) {
            return false;
        }
        bool left = check(root->left, low, root->val);
        bool right = check(root->right, root->val, high);
        bool ans = left && right;
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        long long low = LLONG_MIN;
        long long high = LLONG_MAX;
        return check(root,low,high);
    }
};