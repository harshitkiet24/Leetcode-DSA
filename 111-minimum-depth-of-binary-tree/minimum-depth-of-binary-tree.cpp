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
    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
         if (root->left == nullptr)
        return right + 1;

         if (root->right == nullptr)
        return left + 1;

        return min(left,right) + 1;
    }
    int minDepth(TreeNode* root){
        return depth(root);
    }
};