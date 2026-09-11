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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(inorder,0,inorder.size()-1,postorder,postorder.size()-1,0,mp);
        return root;
    }
    TreeNode* build(vector<int>& inorder,int inStart,int inEnd,vector<int>&postorder,int postStart,int postEnd,map<int,int> &mp){
        if(postStart < postEnd || inStart > inEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postStart]);
        int inroot = mp[root->val];
        int numsleft = inroot - inStart;
        int numsright = inEnd - inroot;

        root->right = build(inorder,inroot+1,inEnd,postorder,postStart-1,postStart-numsright,mp);
        root->left = build(inorder,inStart,inroot-1,postorder,postStart-numsright-1,postEnd,mp);
        return root;
    }
};