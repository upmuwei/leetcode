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
    bool isSymmetric(TreeNode* root) {
        vector<int> left, right;
        vector<int> leftIndex, rightIndex;
        inOrder(root->left, left,leftIndex,0);
        rightOrder(root->right, right,rightIndex,0);
        if(left.size() != right.size()) {
            return false;
        }
        for(int i =0; i < left.size(); i++) {
            if(left[i] != right[i] || leftIndex[i] != rightIndex[i]) {
                return false;
            }
        }
        return true;
    }

    void inOrder(TreeNode * root, vector<int> &p, vector<int> &index,int g) {
        if(root == nullptr) {
            return;
        }
        inOrder(root->left,p,index,0);
        p.push_back(root->val);
        index.push_back(g);
        inOrder(root->right,p,index,1);
    }

    void rightOrder(TreeNode * root, vector<int> &p, vector<int> &index, int g) {
        if(root == nullptr) {
            return;
        }
        rightOrder(root->right, p,index,0);
        p.push_back(root->val);
        index.push_back(g);
        rightOrder(root->left, p,index,1);
    }
};