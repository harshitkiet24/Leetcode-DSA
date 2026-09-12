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
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        stack<TreeNode*> st;
        queue<TreeNode*> q;
        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            q.push(temp);
            if (temp->right) {
                st.push(temp->right);
            }
            if (temp->left) {
                st.push(temp->left);
            }
        }
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            temp->left = nullptr;
            if(!q.empty()){
            temp->right = q.front();
            }
            else{
            temp->right = nullptr;
            }
        }

    }
};