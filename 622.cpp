class MyCircularQueue {
    int length;
    int size;
    int front;
    int back;
    int *p;
public:
    MyCircularQueue(int k) {
        length = k;
        p = new int[k];
        front = 0;
        back = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(size >= length) {
            return false;
        }
        p[back++] = value;
        back %= length;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size <= 0) {
            return false;
        }
        size--;
        front++;
        front %= length;
        return true;
    }
    
    int Front() {
        if(size <=0) {
            return -1;
        }
        return p[front];
    }
    
    int Rear() {
        if(size <=0) {
            return -1;
        }
        if(back == 0)
            return p[length - 1];
        return p[back - 1];
    }
    
    bool isEmpty() {
        if(size <=0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size >= length) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */