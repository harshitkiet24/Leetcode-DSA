/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

    if (root == nullptr) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    bool lefttoright = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            int index = lefttoright ? i : (size - 1 - i);

            ans[index] = node->val;

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }

        lefttoright = !lefttoright;
        result.push_back(ans);
    }

    return result;
}
};