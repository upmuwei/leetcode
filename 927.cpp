class Solution {
public:
    set<vector<int>> looked;
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> result(2, -1);
        int low = 0, high = arr.size() - 1;
        if(arr[0] == 0 || arr[arr.size() -1] == 0) {
            if(is_equal(arr, 0, arr.size() - 1)) {
                while(arr[low] == 0&&low < high) {
                    low++;
                }
                while(arr[high] == 0) {
                    high--;
                }
            } else {
                result[0] = low, result[1] = high;
                return result;
            }
        }
        if(!seek(arr, low, high, result)) {
            result[0] = result[1] = -1;
        }
        return result; 
    }

    bool seek(vector<int>& arr, int low, int high, vector<int>& result) { 
        result[0] = low;
        result[1] = high;
        if(looked.count(result)) {
            return false;
        }
        looked.insert(result);
        int sign = is_equal(arr, low, high);  
        if(!sign) {
            result[0] = low;
            result[1] = high;
            return true;
        }
        if(sign > 0) {
            return false;
        }
        if(low + 2 >= high) {
            return false;
        }
        if(sign == -1) {
            return seek(arr, low, high - 1, result);
        } else if(sign == -2){
            return seek(arr, low + 1, high, result);
        } {
            return seek(arr, low, high - 1, result) || seek(arr, low + 1, high, result);
        }
        return false;
    }

    
int is_equal(vector<int>& arr, int low, int high) {
        int i = 0, j = low + 1, k = high;
        while(arr[i] == 0 &&i <= low) {
            i++;
        }
        while(arr[j] == 0 && j < high) {
            j++;
        }
        while(arr[k] == 0 && k < arr.size()) {
            k++;
        }
        int length1 = low - i + 1, length2 = high - j, length3 = arr.size() - k;
        if(length1 > length2 || length3 > length2) {
            return 1;
        }
        if(length1 > length3) {
            return -1;
        } else if(length1 < length3) {
            return -2;
        } else if(length1 < length2) {
            return -3;
        }
        for(int t = 0; t < length1; t++) {
            if(arr[i + t] > arr[j + t] ||arr[k + t] > arr[j + t]) {
                return 1;
            } else if(arr[i + t] > arr[k + t]) {
                return -1;
            } else if(arr[i + t] < arr[k + t]) {
                return -2;
            } else if(arr[i + t] < arr[j + t]) {
                return -3;
            }
        } 
        return 0;
    }                                                   
};