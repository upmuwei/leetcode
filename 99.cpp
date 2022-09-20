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
    TreeNode* p = nullptr;
    TreeNode* p1 = nullptr;
    TreeNode* p2 = nullptr;
    void recoverTree(TreeNode* root) {
        seek(root);
        swap(p1->val, p2->val);
    }

    void seek(TreeNode* root) {
        if(root != nullptr) {
            seek(root->left);
            if(p == nullptr) {
                p = root;
            } else if(root->val > p->val) {
                p = root;
            } else {
                if(p1 == nullptr) {
                    p1 = p;
                }
                p2 = root;
                p = root;
            }
            seek(root->right);
        }  
    }
};