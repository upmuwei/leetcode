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
private:
    TreeNode* p = nullptr;
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        travese(root, nodes);
        if(nodes.size() != 0) {
            for(int i = 0; i < nodes.size() - 1; i++) {
                nodes[i]->left = nullptr;
                nodes[i]->right = nodes[i + 1];
            }

        }
    }

    void travese(TreeNode * root, vector<TreeNode*>& p) {
        if(root == nullptr) {
            return;
        }
        p.push_back(root);
        travese(root->left, p);
        travese(root->right, p);      
    }
};