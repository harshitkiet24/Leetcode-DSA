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
    int pathsum(TreeNode* root,int &maxi){
        if(root == nullptr){
            return 0;
        }
        int leftsum = max(0,pathsum(root->left,maxi));
        int rightsum = max(0,pathsum(root->right,maxi));
        maxi = max(maxi,root->val + leftsum + rightsum);
        return (root->val + max(leftsum,rightsum));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        pathsum(root,maxi);
        return maxi;
    }
};