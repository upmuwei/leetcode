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
    TreeNode *root = nullptr;

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        construct(nums, 0);
        return root;
    }

    void construct(vector<int>& nums, int index) {
        TreeNode *p = new TreeNode(nums[index], nullptr, nullptr);
        if(root == nullptr) {
            root = p;
        }
        else {
            TreeNode *t = root;
            if(t->val < p->val) {
                p->left = root;
                root = p;
            } else {
                while(t->right != nullptr && (t->right->val) > p->val) {
                    t = t->right;
                }
                p->left = t->right;
                t->right = p;
            }
        }
        index++;
        if(index == nums.size()) {
            return;
        }
        construct(nums, index);
         
    }
};