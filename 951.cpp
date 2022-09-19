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

    bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2){
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2){
            return false;
        }
        if(root1->val == root2->val){
            return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) || flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        }
        else{
            return false;
        }
    }

    bool flipEquiv2(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> nodes1, nodes2;
        nodes1.push(root1);
        nodes2.push(root2);
        while(nodes1.size()&&nodes2.size()) {
            TreeNode* p1 = nodes1.front();
            TreeNode* p2 = nodes2.front();
            if(p1 == nullptr&&p2 == nullptr) {
                nodes1.pop();
                nodes2.pop();
                continue;
            } else if(p1 == nullptr||p2 == nullptr) {
                return false;
            }
            if(p1->left == nullptr && p2->left == nullptr && p1->right == nullptr && p2->right == nullptr) {                
                nodes1.pop();
                nodes2.pop();
                continue;
            }
            if(p2->left == nullptr && p1->left != nullptr) {
                swap(p1->left, p1->right);
                
                if(p1->left != nullptr) {
                    return false;
                }
                if(p2->right == nullptr || p2->right->val != p1->right->val) {
                    return false;
                }
               
            }
            else if(p1->left == nullptr && p2->left != nullptr) {
                
                swap(p1->left, p1->right);
                if(p1->left == nullptr || p1->left->val != p2->left->val) {
                    return false;
                }
              
                if(p2->right != nullptr) {
                    return false;
                }
                  
            }
            else if(p1->left != nullptr && p2->left != nullptr && p1->left->val != p2->left->val) {
                swap(p1->left, p1->right);
                if(p1->left == nullptr || p1->left->val != p2->left->val) {
                    return false;
                }
            }
            if(p2->right == nullptr && p1->right == nullptr) {

            }
            else if(p2->right == nullptr || p1->right == nullptr) {
                return false;
            }
            else if( p1->right->val != p2->right->val) {
                return false;
            }
            nodes1.pop();
            nodes2.pop();
            if(p1->left != nullptr) {
                nodes1.push(p1->left);
                nodes2.push(p2->left);
            }
            if(p1->right != nullptr) {
                nodes1.push(p1->right);
                nodes2.push(p2->right);
            }
        }
        return  isEqual(root1, root2);
    }

    bool isEqual(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) {
            return true;
        } else if(root1 == nullptr || root2 == nullptr) {
            return false;
        }
        if(root1->val != root2->val) {
            return false;
        }
        return isEqual(root1->left, root2->left) &&isEqual(root1->right, root2->right);
    }
};