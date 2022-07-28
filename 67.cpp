class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int t = 0;
        int aLength = a.size() -1, bLength = b.size() - 1;
        while(aLength >= 0 && bLength >= 0) {
            t += a[aLength] + b[bLength] - '0';
            if(t == '3') {
                s.insert(s.begin(), '1');
                t = 1;
            }
            else if(t == '2') {
                s.insert(s.begin(), '0');
                t = 1;
            } else {
                s.insert(s.begin(), t);
                t = 0;
            }
            aLength--;
            bLength--;
        }
        if(aLength >= 0) {
            int len = aLength;
            while(aLength >= 0) {
                t += a[aLength];
                if(t == '2') {
                    a[aLength] = '0';
                    t = 1;
                }
                else {
                    a[aLength] = t;
                    t = 0;
                    break;
                }
                aLength--;
            }
            s = a.substr(0, len + 1) + s;
        }
        if(bLength >= 0) {
            int len = bLength;
             while(bLength >= 0) {
                t += b[bLength];
                if(t == '2') {
                    b[bLength] = '0';
                    t = 1;
                }
                else {
                    b[bLength] = t;
                    t = 0;
                    break;
                }
                bLength--;
            }
            s = b.substr(0, len + 1) + s;
        }
        if(t) {
            s.insert(s.begin(), '1');
        }
        return s;
    }
};