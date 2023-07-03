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
public:
    Node* connect(Node* root) {
        if(root == nullptr) {
            return nullptr;
        }
        queue<Node*> q;
        q.push(root);
        Node * prev = nullptr;
        root->next = NULL;
        Node * sign = root;
        while(q.size()) {
            Node*p = q.front();
            q.pop();
            if(p->left == nullptr) {
                return root;
            }
            q.push(p->left);
            q.push(p->right);
            if(prev != nullptr) {
                prev->next = p->left;
            }
            p->left->next = p->right;
            if(sign == p) {
                sign = p->right;
                prev = nullptr;
            } else {
                prev = p->right;
            }
        }
        return root;
    }
};