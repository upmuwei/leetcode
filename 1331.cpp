class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> t(arr.begin(), arr.end());
        vector<int> copy(t.begin(), t.end());
        // sort(copy.begin(), copy.end());
        vector<int> index;
        for(int i = 0; i < arr.size(); i++) {
            int t = arr[i];
            int low = 0, high = copy.size() - 1;
             int middle = (low + high) / 2;
           
    
            while(low <= high) {
                if(t == copy[middle]) {
                    index.push_back(middle + 1);
                    break;
                }
                else if(t > copy[middle]) {
                    low = middle + 1;
                } else {
                   
                    high = middle - 1;
                }
                middle = (low + high) / 2;
            }
        }
        return index;
    }
};