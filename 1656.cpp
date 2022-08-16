class OrderedStream {
public:
    int ptr;
    string *s;
    OrderedStream(int n) {
        ptr = 1;
        s = new string[n];
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> result;
        if(idKey == ptr) {
            s[idKey - 1] = value;
            while(s[idKey - 1] != "") {
                result.push_back(s[idKey - 1]);
                idKey++;
            }
            ptr = idKey;
        } else {
            s[idKey - 1] = value;
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */