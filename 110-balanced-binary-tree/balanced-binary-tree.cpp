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
    int balance(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lefth = balance(root->left);
        if(lefth == -1){
            return -1;
        }
        int righth = balance(root->right);
        if(righth == -1){
            return -1;
        }

        if(abs(lefth-righth)>1){
            return -1;
        }

        return max(lefth,righth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(balance(root)==-1){
            return false;
        }
        return true;
    }
};