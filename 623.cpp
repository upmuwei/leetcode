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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* p = new TreeNode(val, root, nullptr);
            return p;
        }
        insertNode(root,val,  1,depth);
        return root;
    }

    void insertNode(TreeNode* root, int val, int nowDepth, int depth) {
         nowDepth++;
        if(nowDepth == depth) {
            TreeNode* newLeft = new TreeNode(val,root->left, nullptr);
            root->left = newLeft;
            TreeNode* newRight = new TreeNode(val, nullptr, root->right);
            root->right = newRight;
            return;
        }
       
        if(root->left != nullptr) {
            insertNode(root->left, val, nowDepth, depth);
        }
        if(root->right != nullptr) {
            insertNode(root->right, val, nowDepth, depth);
        }
    }
  };