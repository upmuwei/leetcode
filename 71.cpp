class Solution {
public:
    string simplifyPath(string path) {
        int length = 0, pointLength = 0, i = 0;
        bool sign = true;
        for(; i < path.size(); i++) {
            if(path[i] == '/') {
                sign = true;
                if(pointLength == 2) {
                     path.erase(path.begin() + i - 1);
                     i--;
                     path.erase(path.begin() + i - 1);
                     i--;
                     if(i-1 > 0) {
                        path.erase(path.begin() + i - 1);
                        i--;
                     }
                    while(i -1 >= 0 && path[i - 1] != '/') {
                        path.erase(path.begin() + i - 1);
                        i--;
                    }
                    if(i-1 >= 0) {
                        path.erase(path.begin() + i - 1);
                        i--;
                    }
                } else if(pointLength == 1) {
                    path.erase(path.begin() + i - 1);
                    i--;
                    path.erase(path.begin() + i - 1);
                    i--;
                }
                pointLength = 0;
                 length++;
                if(length == 2) {
                    path.erase(path.begin() + i);
                    length--;
                    i--;
                }
            } else if(path[i] == '.' &&sign){
                length = 0;
                pointLength++;
            } else {
                sign = false;
                length = 0;
                pointLength = 0;
            }
        }
        if(pointLength == 2) {
                     path.erase(path.begin() + i - 1);
                     i--;
                     path.erase(path.begin() + i - 1);
                     i--;
                     if(i-1 > 0) {
                        path.erase(path.begin() + i - 1);
                        i--;
                     }
                    while(i -1 >= 0 && path[i - 1] != '/') {
                        path.erase(path.begin() + i - 1);
                        i--;
                    }  
                    if(i-1 > 0) {
                        path.erase(path.begin() + i - 1);
                        i--;
                    }
                } else if(pointLength == 1) {
                    path.erase(path.begin() + i - 1);
                    i--;
                    if(i-1 >0) {
                        path.erase(path.begin() + i - 1);
                        i--;
                    }
                    
                }
        if(path.size()!=1) {
            if(path[path.size() -1] == '/') {
                path.pop_back();
            }
        }
        return path;
    }
};