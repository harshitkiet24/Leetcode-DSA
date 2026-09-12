/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        queue<TreeNode*> q;
        q.push(root);
        string s = "";
        s += to_string(root->val);
        s += ",";
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left == nullptr) {
                s += ".,";
            } else {
                 s += to_string(temp->left->val);
                s += ",";
                q.push(temp->left);
            }
            if (temp->right == nullptr) {
                s += ".,";
            } else {
                s += to_string(temp->right->val);
                s += ",";
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        string str;
        stringstream s(data);
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == ".") {
                temp->left = nullptr;
            } else {
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }
            getline(s, str, ',');
            if (str == ".") {
                temp->right = nullptr;
            } else {
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));