#include <iostream>
#include <string>

using namespace std;

bool isHui(string& s) {
    int left = 0, right = s.size() - 1;
    while(left < right) {
        if(s[left] == s[right]) {
            left++;
            right--;
        } else {
            if(s[left] == 'd' || s[left] == 'q' || s[left] == 'p') {
                s[left] = 'b';
            }
            if(s[right] == 'd' || s[right] == 'q' || s[right] == 'p') {
                s[right] = 'b';
            }
            if(s[left] == 'u') {
                s[left] = 'n';
            }
            if(s[right] == 'u') {
                s[right] = 'n';
            }
            if(s[left] == s[right]) {
                left++;
                right--;
            } else {
                if((s[left] == 'w' && s[right] == 'v') || (s[left] == 'v' && s[right] == 'w')) {
                    if(s[left] == 'w') {
                        right--;
                        s[left] = 'v';
                    } else {
                        left++;
                        s[right] = 'v';
                    }
                }
                else if((s[left] == 'm' && s[right] == 'n') || (s[left] == 'n' && s[right] == 'm')) {
                    if(s[left] == 'm') {
                        right--;
                        s[left] = 'n';
                    } else {
                        left++;
                        s[right] = 'n';
                    }
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    string s;
    s = "wovv";
    cout << (isHui(s) ? "YES" : "NO") << endl;
    s = "bod";
    cout << (isHui(s) ? "YES" : "NO") << endl;
    s = "pdd";
    cout << (isHui(s) ? "YES" : "NO") << endl;
    s = "moom";
    cout << (isHui(s) ? "YES" : "NO") << endl;
    s = "lalalai";
    cout << (isHui(s) ? "YES" : "NO") << endl;
    return 0;
}