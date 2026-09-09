/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) {
                q.push(temp->left);
                parent[temp->left] = temp;
            }
            if (temp->right) {
                q.push(temp->right);
                parent[temp->right] = temp;
            }
        }
        int distance = 0;
        unordered_set<TreeNode*> st;
        q.push(target);
        st.insert(target);
        while (!q.empty()) {
            int size = q.size();
            if (distance == k) {
                break;
            }
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left && !st.count(temp->left)) {
                    q.push(temp->left);
                    st.insert(temp->left);
                }
                if (temp->right && !st.count(temp->right)) {
                    q.push(temp->right);
                    st.insert(temp->right);
                }
                if (parent[temp] && !st.count(parent[temp])) {
                    q.push(parent[temp]);
                    st.insert(parent[temp]);
                }
            }
            distance++;
        }
        vector<int> result;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};