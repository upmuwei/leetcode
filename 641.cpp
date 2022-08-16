class MyCircularDeque {
//认真读题，不要觉得很熟悉就不认真读，细节很重要
private:
    int *p;
    int size, right;
public:
    MyCircularDeque(int k) {
        size = k;
        right = 0;
        p = new int[k];
    }
    
    bool insertFront(int value) {
        if(right >= size) {
            return false;
        }
        for(int i = right; i >= 1; i--) {
            p[i] = p[i-1];
        }
        right++;
        p[0]= value;
        return true;
    }
    
    bool insertLast(int value) {
        if(right >= size) {
            return false;
        }
        p[right++] = value;
        return true;
    }
    
    bool deleteFront() {
        if(right == 0) {
            return false;
        }
        for(int i = 1; i < right; i++) {
            p[i - 1] = p[i];
        }
        right--;
        
        return true;
    }
    
    bool deleteLast() {
        if(right == 0) {
            return false;
        }
        right--;
        return true;
    }
    
    int getFront() {
        return right == 0 ? -1 :p[0];
    }
    
    int getRear() { 
        return   right == 0? -1 : p[right -1];
    }
    
    bool isEmpty() {
        return right == 0? true :false;
    }
    
    bool isFull() {
        return right == size?true:false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */