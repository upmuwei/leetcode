#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        map<int,int> depthToWidth;
        int maxWidth = 1;
        if(root->left != nullptr) {
            travese(root->left, maxWidth, -1, depthToWidth, 1);
        }
        if(root->right != nullptr) {
            travese(root->right, maxWidth, 1, depthToWidth, 1);
        }
        
        return maxWidth;
    }

    void travese(TreeNode * root, int& maxWidth, int index, map<int, int>& depthToWidth, int depth) {
        if(depthToWidth[depth] == 0) {
            depthToWidth[depth] = index;
        } else {
            int t = index - depthToWidth[depth];
            if((index < 0 && depthToWidth[depth] < 0) || (index > 0 && depthToWidth[depth] > 0)) {
                t++;
            }
            if(t > maxWidth) {
                maxWidth = t;
            }
        }
        if(index > 0) {
            if(root->left != nullptr) {
                travese(root->left, maxWidth, 2 * index - 1, depthToWidth, depth + 1);
            }
            if(root->right != nullptr) {
                travese(root->right, maxWidth, 2 * index, depthToWidth, depth + 1);
            }    
        }
        else {
            if(root->left != nullptr) {
                travese(root->left, maxWidth, 2 * index, depthToWidth, depth + 1);
            }
            if(root->right != nullptr) {
                travese(root->right, maxWidth, 2 * index + 1, depthToWidth, depth + 1);
            } 
        }
       
    }

    int widthOfBinaryTree2(TreeNode* root) {
        int  min = 0;
        queue<TreeNode *> nodes;
        queue<int> nullNums;
        TreeNode *index = root;
        int maxWidth = 1;
        int count = 0;
        int leftCount = 0;
        nodes.push(root);
        nullNums.push(count);
        while(nodes.size()) {
            TreeNode * t = nodes.front();
            int tCount = nullNums.front();
            nullNums.pop();
            nodes.pop();
            if(t == index) {
                index = nullptr;
                min = 1;
                count = 0;
                leftCount = 0;
            }else {
                min++;
            }
            if(min + tCount > maxWidth) {
                maxWidth = min + tCount;
            }
           
            if(t->left != nullptr) {
                nodes.push(t->left);
                if(index == nullptr) {
                    nullNums.push(0);
                } else {
                    nullNums.push(count +2 * tCount - 2 * leftCount);
                }
                
            }else {
                if(index != nullptr) {
                    count++;
                }
            }
             if(index == nullptr && t->left != nullptr) {
                index = t->left; 
                leftCount = tCount;
            }
            if(t->right != nullptr) {
                nodes.push(t->right);
                if(index == nullptr) {
                    nullNums.push(0);
                } else {
                    nullNums.push(count +2 * tCount - 2 * leftCount);
                }
            } else {
                if(index != nullptr) {
                    count++;
                }
            }
            if(index == nullptr && t->right != nullptr) {
                index = t->right;
                leftCount = tCount;
            } 
        }
        return maxWidth;
    }
};