#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string s1(argv[1]);
    string s2(argv[1]);
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] == '1') {
            if(i + 1 < s1.size()) {
                s1[i] = '0';
                s1[i + 1] = (s1[i + 1] == '0' ? '1' : '0');
                count1++;
            }
            if(i + 2 < s1.size()) {
                s1[i + 2] = (s1[i + 2] == '0' ? '1' : '0');
            }
        } 
    }
    for(int i = s2.size() - 1; i >= 0; i--) {
        if(s2[i] == '1') {
            if(i - 1 >= 0) {
                s2[i] = '0';
                s2[i - 1] = (s2[i - 1] == '0' ? '1' : '0');
                count2++;
            }
            if(i - 2 >= 0) {
                s2[i - 2] = (s2[i - 2] == '0' ? '1' : '0');
            }
        }
    }
    if(s1[s1.size() - 1] == '0' && s2[0] == '0') {
        cout << (count1 < count2 ? count1 : count2) << endl;
    } else if(s1[s1.size() - 1] || '0' && s2[0] == '0') {
        cout << (count1 != 0 ? count1 : count2) << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}