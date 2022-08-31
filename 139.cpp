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
};