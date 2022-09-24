class MyLinkedList {
private:
    struct Node {
        int val;
        Node * next = nullptr;
        Node () {};
        Node(int val) { this->val = val;};
    };
    
    Node * root;
public:
    MyLinkedList() {
        root = nullptr;
    }
    
    int get(int index) {
        if(root == nullptr) {
            return -1;
        } 
        Node * p = root;
        int i = 0;
        while(p != nullptr) {
          
           if(i == index) {
               return p->val; 
           } 
           i++;
           p = p->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node *p = new Node(val);
        p->next = root;
        root = p;
    }
    
    void addAtTail(int val) {
        if(root == nullptr) {
            root = new Node(val);
            return; // 注意细节，if完成之后就结束了
        }
        Node *p = root;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = new Node(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0 && root == nullptr) {
            root = new Node(val);
            return;
        }
        if(index == 0) {
            Node *p = new Node(val);
            p->next = root;
            root = p;
        }
        else if(root != nullptr) {
            Node *p = root;
            int i = 1;
            while(p != nullptr) {
                if(i == index) {
                    Node* t = new Node(val);
                    t->next = p->next;
                    p->next = t;
                } 
                i++;
                p = p->next;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if(root == nullptr) {
            return;
        }
        if(index == 0) {
            Node* t = root;
            root = root->next;
            delete(t);
        } else {
            int i = 1;
            Node * p = root;
            while(p->next != nullptr) {
                if(i == index) {
                    Node* t = p->next;
                    p->next = p->next->next;
                    delete(t);
                    return;
                }
                p = p->next;
                i++;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */