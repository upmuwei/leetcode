#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> s;
        int index = 0;
        int position =  sentence.find(" ", index);
        while(position != - 1) {
            s.push_back(sentence.substr(index,  position-index));
            index = position + 1;
            position =  sentence.find(" ", index);
        }
        s.push_back(sentence.substr(index, sentence.size() - index));
        index = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i].find(searchWord) == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};

int main() {
    string sentence = "hellohello hellohellohello";
    string searchWord = "ell";
    Solution so;
    cout << so.isPrefixOfWord(sentence, searchWord);
    return 0;
}