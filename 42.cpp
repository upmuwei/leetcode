class Solution {
public:
    int trap(vector<int>& height) {
        int left =0, right = 0, length = height.size();
        int area = 0;
        for(int i = 0; i < length; i++) {
            left = i + 1;
            if(left >= length || height[left] > height[i]) {
                continue;
            }
            right = left;
            int j = left + 1;
            for(;j < length; j++) {
                if(height[j] > height[left] && height[j] > height[right]) {
                    right = j;
                }
                if(height[j] >= height[i]) {
                    break;
                }
            }
            if(j == length) {
                j = right;
            }
            if(j < length && j > left) {

                int min = height[i] > height[j] ? height[j] : height[i];
                for(int t = i + 1; t < j; t++) {
                    area += min - height[t];
                }
                i = j -1;
            }           
        }
        return area;
    }
};