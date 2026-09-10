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
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
       int lh = 0;
       TreeNode*temp = root;
       while(temp != nullptr){
        temp = temp->left;
        lh++;
       }
       int rh = 0;
       temp = root;
        while(temp != nullptr){
        temp = temp->right;
        rh++;
       }
       int ans = 0;
       if(lh == rh){
        ans = pow(2,lh) - 1;
       return ans;
       }
       return 1 + countNodes(root->left) + countNodes(root->right);
    }
};