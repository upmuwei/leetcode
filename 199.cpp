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
    //检查，不要着急提交
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<int> result;
        vector<TreeNode *> q;
        q.push_back(root);
        TreeNode * end = root;
        int index = 0;
        while(index < q.size()) {
            TreeNode* p = q[index++];
            if(end == p) {
                result.push_back(p->val);
                if(p->left != nullptr) {
                    q.push_back(p->left);
                    end = p->left;
                }   
                if(p->right != nullptr) {
                    q.push_back(p->right);
                    end = p->right;
                }
                if(end == p) {
                    int t = index - 1;
                    while(true) {
                        t--;
                        if(t < 0) {
                            break;
                        }
                        TreeNode *node = q[t];
                        if(node->right != nullptr&& node->right != p) {
                            end = node->right;
                            break;
                        } else if(node->left != nullptr && node->left != p) {
                            end = node->left;
                            break;
                        } else if(node->left != nullptr || node->right != nullptr){
                            break;
                        }
                    }
                }

            } else {
                if(p->left != nullptr) {
                    q.push_back(p->left); 
                }   
                if(p->right != nullptr) {
                    q.push_back(p->right);
                }
            }
        }
        return result;
    }
};