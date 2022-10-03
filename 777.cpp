class Solution {
public:
    bool canTransform(string start, string end) {
        for(int i = 0; i < start.size(); i++) {
            if(start[i] != end[i]) {
                if(!adjust(start, end, i)) {
                    return false;
                }
            }
        }    
        return true; 
    }

    bool adjust(string& start, string& end, int index) {
        // if(start.size() == index +1) {
        //     return false;
        // }
        if(end[index] == 'L') {
            int i = index;
            for(; i < start.size(); i++) {
                if(start[i] == 'L') {
                    break;
                } else if(start[i] == 'R') {
                    return false;
                }
            }
            if(i == start.size()) {
                return false;
            }
            swap(start[index], start[i]);
            return true;
        } else {
            int i = index;
            for(; i < start.size(); i++) {
                if(start[i] == 'X') {
                    break;
                } else if(start[i] == 'L') {
                    return false;
                }
            }
            if(i == start.size()|| i == index) {
                return false;
            }
            swap(start[index], start[i]);
            return true;
        }
    }   
};