#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    long number = 0;
    int temp = 1;
    int negative = 0;
    int i = 0;
    while(s[i] == ' ')
        i++;
    if(s[i] == '-'|| s[i] == '+') {
        if(s[i] == '-')
            negative = 1;
        i++;
    }
    while(s[i] == '0')
        i++;    
    for(; i < s.size(); i++) {
        if(s[i] >='0' && s[i] <= '9') {
            number = number * 10 + (s[i] - '0');
            if(number != (int)number)
                break;
        }
        else
            break;
    }
    if(negative)
        number = -number;
    if(number != (int)number) {
        if(number > 0)
            number = 0x7fffffff;
        else 
            number = 0x80000000; 
    }
    cout << (int)number << endl;
    return 0;
}