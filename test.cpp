#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 0;
    vector<char> stack;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(c == '<' || c == '{' || c == '[' || c == '(') {
            stack.push_back(c);
        } else if(c == '>' || c == '}' || c == ']' || c == ')') {
            if(stack.size() > 0) {
                char left = stack.back();
                if((left == '<' && c == '>') || (left =='{' && c == '}')
                    || (left == '[' && c == ']') || (left == '(' && c == ')')) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(c);
            }
            
        }
    }
    count += stack.size() / 2;
    cout << count;
    return 0;
}