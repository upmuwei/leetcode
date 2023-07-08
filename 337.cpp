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
    map<TreeNode*, int> robResult;
    map<TreeNode*, int> noRobResult;
public:
    int rob(TreeNode* root) {
        int money1 = rob(root, true), money2 = rob(root, false);
        return max(money1, money2);
    }

    int rob(TreeNode * root, bool robed) {
        if(root == nullptr) {
            return 0;
        }
        if(robed) {
            if(robResult.find(root) != robResult.end()) {
                return robResult[root];
            }
            int t = root->val + rob(root->left, false) + rob(root->right, false);
            robResult[root] = t;
            return t;
        } else {
            if(noRobResult.find(root) != noRobResult.end()) {
                return noRobResult[root];
            }
            int money1 = max(rob(root->left, true), rob(root->left, false));
            int money2 = max(rob(root->right, true), rob(root->right, false));
            noRobResult[root] = money1 + money2;
            return money1 + money2;
        }
    }
};