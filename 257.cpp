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
    vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<int> s;
        getPath(root, s);
        return result;
    }

    void getPath(TreeNode * root, vector<int>& s) {
        if(root == nullptr) {
            return;
        }
        s.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            string t;
            t.append(to_string(s[0]));
            for(int i = 1; i < s.size(); i++) {
                t.append("->" + to_string(s[i]));
            }
            result.push_back(t);
            return;
        }
        if(root->left != nullptr) {
            getPath(root->left, s);
            s.pop_back();
        }
        if(root->right != nullptr) {
            getPath(root->right, s);
            s.pop_back();
        }
    }
};