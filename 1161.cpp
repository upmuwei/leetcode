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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode *> queue;
        queue.push_back(root);
        int max = root->val;
        int maxIndex = 1;
        int index = 0;
        int tmp = 0;;
        TreeNode* t;
        TreeNode *tNode = nullptr;
        t = root;
        while(queue.size()) {
            TreeNode * p = queue.front();
            queue.erase(queue.begin());
            tmp += p->val;
            if(t == p) {
                index ++;
                if(tmp > max) {
                    // cout << tmp << " " << index << " " << max << endl;
                    max = tmp;
                    maxIndex = index;
                }
                if(p->left != nullptr) {
                    tNode = p->left;
                    queue.push_back(tNode);
                }
                if(p->right != nullptr) {
                    tNode = p-> right;
                    queue.push_back(tNode);
                } 
                tmp = 0;
                t = tNode;
            } else {
                if(p->left != nullptr) {
                    tNode = p->left;
                    queue.push_back(tNode);
                }
                if(p->right != nullptr) {
                    tNode = p-> right;
                    queue.push_back(tNode);
                } 
            }
        }
        return maxIndex;
    }
};