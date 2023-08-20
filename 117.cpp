/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    map<int, Node*> backs;
public:
    Node* connect(Node* root) {
        if(root == nullptr) {
            return nullptr;
        }
        compute(root, 0);
        return root;
    }

    void compute(Node* root, int high) {
        if(root == nullptr) {
            return;
        }
        if(backs.find(high) != backs.end()) {
            root->next = backs[high];
        }
        backs[high] = root;
        compute(root->right, high + 1);
        compute(root->left, high + 1);
    }
};