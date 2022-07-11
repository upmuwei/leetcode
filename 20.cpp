#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    string s;
    cin >> s;
    vector<char> match;
    int length = s.size();
    int i = 0;
    while(i < length) {
        if(s[i] == ']') {
            if(match.size() ==0) {
                return false;
            }
            char t = match.back();
            if(t == '[') {
                match.pop_back();
            } else {
                cout << false;
            }
        } else if(s[i] == '}') {
            if(match.size() ==0) {
                cout << false;
            }
            char t = match.back();
            if(t == '{') {
                match.pop_back();
            } else {
                cout << false;
            }
        } else if(s[i] == ')') {
            if(match.size() ==0) {
                cout << false;
            }
            char t = match.back();
            if(t == '(') {
                match.pop_back();
            } else {
                cout << false;
            }
        } else {
            match.push_back(s[i]);
        }
        i++;
    }
    if(match.size() == 0) {
        cout << true;
    }
    cout << false;
    return 0;
}