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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
        return nullptr;
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int index = 0;
        if (it != inorder.end()) {
            index = it - inorder.begin();
        }
        vector<int>leftin(inorder.begin(),inorder.begin()+index);
        vector<int>leftpre(preorder.begin()+1,preorder.begin()+index+1);
        TreeNode* l = buildTree(leftpre,leftin);
        vector<int>rightin(inorder.begin()+index+1,inorder.end());
        vector<int>rightpre(preorder.begin()+leftpre.size()+1,preorder.end());
        TreeNode* r = buildTree(rightpre,rightin);

        TreeNode* root = new TreeNode(preorder[0]);
        root->left = l;
        root->right = r;
        return root;
    }
    };