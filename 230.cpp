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
    int index = 0;
    int val = -1;

public:
    int kthSmallest(TreeNode* root, int k) {
        middleVisited(root, k);
        return val;
    }


    void middleVisited(TreeNode* root, int k) {
       if(root == nullptr) {
           return;
       } 
       middleVisited(root->left,k);
        index++;
        if(index == k) {
            val = root->val;
            return;
        }
       middleVisited(root->right,k);
    }
};