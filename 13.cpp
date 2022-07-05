#include <iostream>
#include <map>
#include <string>

using namespace std;
int main() {

    string s; 
    cin >> s;
    map<char, int> transform;
    transform.insert(make_pair('I', 1));
    transform.insert(make_pair('V', 5));
    transform.insert(make_pair('X', 10));
    transform.insert(make_pair('L', 50));
    transform.insert(make_pair('C', 100));
    transform.insert(make_pair('D', 500));
    transform.insert(make_pair('M', 1000));
    int sum = 0;
    int money = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        int temp = transform[s[i]];
        if(temp < money) {
            sum -= temp;
        } else {
            sum += temp;
        }
        money = temp;
    } 
    cout << sum << endl;
    return 0;
}