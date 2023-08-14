#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> sonArr;
void dfs(vector<int>& elem, int index, vector<int>& array) {
    if(index == elem.size()) {
        return;
    }
    array.push_back(elem[index]);
    sonArr.insert(array);
    dfs(elem, index + 1, array);
    array.pop_back();  
} 

int main() {
    vector<int> elem1({1, 2,3});
    vector<int> elem2({2, 3,1});
    vector<int> array;
    for(int i = 0; i < elem1.size(); i++) {
        dfs(elem1, i, array);
    }
    for(int i = 0; i < elem2.size(); i++) {
        dfs(elem2, i, array);
    }    
    cout << sonArr.size();
    return 0;
}