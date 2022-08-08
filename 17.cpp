#include <iostream>
#include <string>
#include <vector>
using namespace std;
void getCombination(string digits, int p, string s) ;
string project[10];
vector<string> results;

int main()
{
    string digits = "23";
    project[2] = "abc";
    project[3] = "def";
    project[4] = "ghi";
    project[5] = "jkl";
    project[6] = "mno";
    project[7] = "pqrs";
    project[8] = "tuv";
    project[9] = "wxyz";
    getCombination(digits, 0, "");
    for(int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return 0;
}


void getCombination(string digits, int p, string s) {
    if(digits.size() == p) {
        results.push_back(s);
        return;
    }
    for(int i = 0; i < project[digits[p] - '0'].size(); i++) {
        s.push_back(project[digits[p] - '0'][i]);
        getCombination(digits, p + 1, s); 
        s.pop_back();
    }
    return;
}