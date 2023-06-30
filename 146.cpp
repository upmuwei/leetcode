class LRUCache {
    int capacity;
    int used;
    map<int, int> data;  
    vector<int> v;
public:
    LRUCache(int capacity) {
        used = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = data.find(key);
        if(it != data.end()) {
            for(auto it = v.begin(); it != v.end(); it++) {
                if(*it == key) {
                    v.erase(it);
                    v.insert(v.begin(), key);
                }
            }
            return it->second; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(data.find(key) != data.end()) {
            data[key] = value;
            for(auto it = v.begin(); it != v.end(); it++) {
                if(*it == key) {
                    v.erase(it);
                    v.insert(v.begin(), key);
                }
            }
            return;
        }
        if(used < capacity) {
            data[key] = value;
            used++;
            v.insert(v.begin(), key);
        } else {
            data.erase(v.back());
            v.pop_back();
            v.insert(v.begin(), key);
            data[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */