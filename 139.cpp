class Solution {
private:
    set<int> repeat;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<vector<int>> wordIndex(wordDict.size());
        int i = 0;
        int length;
        for(auto w : wordDict) {
            int position = s.find(w);
            while(position != -1) {
                wordIndex[i].push_back(position);
                position = s.find(w, position + 1);
            }
            i++;
        }
        return match(wordIndex, wordDict,s.size(), 0);
    }

    bool match(vector<vector<int>>& wordIndex, vector<string>& wordDict,int length, int index) {
        if(index == length) {
            return true;
        }
        for(int i = 0; i < wordIndex.size(); i++) {
            for(int j = 0; j < wordIndex[i].size(); j++) {
                if(wordIndex[i][j] == index) {
                    int t = index + wordDict[i].size();
                    if(repeat.count(t) != 0) {
                        continue;
                    }
                    repeat.insert(t);
                    int sign = match(wordIndex, wordDict, length, t);
                    if(sign) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool wordBreak2(string s, vector<string>& wordDict) {
        vector<bool> indexs(s.size() + 1, false);
        indexs[0] = true;
        vector<vector<int>> wordIndex;
        int length;
        for(auto w : wordDict) {
            int position = s.find(w);
            while(position != -1) {
                vector<int> t;
                t.push_back(position);
                t.push_back(w.size());
                wordIndex.push_back(t);
                position = s.find(w, position + 1);
            }
        }
        sort(wordIndex.begin(),wordIndex.end());
        for(int i = 0; i < s.size(); i++) {
            if(indexs[i] == false) {
                continue;
            }
            for(int j = 0; j < wordIndex.size(); j++) {
                if(wordIndex[j][0] == i) {
                    indexs[i + wordIndex[j][1]] = true;
                } else if(wordIndex[j][0] > i) {
                    break;
                }
            }
        }
        return indexs[s.size()];
    }
};