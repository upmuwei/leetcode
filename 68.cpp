class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int size = words.size();
        vector<string> result;
        int length = 0, index = 0;
        for(int i = 0; i < size; i++) {
            length += words[i].size() + 1;
            if(length > maxWidth + 1) {
                int spaceNum = maxWidth - (length - words[i].size() - 2);
                int everySpace = 0;
                int more = 0;
                if(i != index + 1) {
                    everySpace = spaceNum / (i - index - 1) + 1;
                    more = spaceNum - (everySpace - 1) * (i - index - 1); 
                } else {
                    more = spaceNum;
                }
                string s;
                for(int j = index; j < i - 1; j++) {
                    s += words[j];
                    for(int t = 0; t < everySpace; t++) {
                        s.push_back(' ');
                    }
                    if(more) {
                        s.push_back(' ');
                        more--;
                    }
                }
                s += words[i - 1];
                for(int t = 0; t < more; t++) {
                    s.push_back(' ');
                }
                result.push_back(s);
                length = words[i].size() + 1;
                index = i;
            }
        }
        string s;
        for(int j = index; j < size - 1; j++) {
            s += words[j] + " ";
        }
        s += words[size - 1];
        int spaceNum = maxWidth - length + 1;
        for(int t = 0; t < spaceNum; t++) {
            s.push_back(' ');
        }
        result.push_back(s);
        return result;
    }
};