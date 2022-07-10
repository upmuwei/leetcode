#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, p;
    cin >> s >> p;
    int i = 0, j = 0, length1 = s.size(), length2 = p.size();
    while(i < length1 && j < length2) {
        if(p[j] == '.') {
            i++;
            if(p[j + 1] == '*') {
                i = length1;
                j++;
            }
        } else if(s[i] == p[j]) {
            i++;
            if(p[j + 1] == '*') {
                int t = j;
                j++;
                while(s[i] == s[i - 1]) {
                    i++;
                    if(p[j + 1] == p[t]) {
                        j++;
                    }
                }
            }
        } else {
            if(p[j +1] == '*') {
                j++;
            } else {
                i = length1;
            }
        }
        j++;
    }
    bool t = true;
   
    if(i == length1 && j == length2) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }
    return 0;
}