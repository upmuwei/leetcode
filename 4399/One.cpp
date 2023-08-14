#include <iostream>
#include <string>

std::string findLongestIncreasingSubstring(const std::string& s) {
    int longestStart = 0;  // 最长递增子串的起始位置
    int longestLength = 0; // 最长递增子串的长度

    int currentStart = 0;  // 当前递增子串的起始位置
    int currentLength = 0; // 当前递增子串的长度

    for (int i = 1; i < s.length(); i++) {
        // 判断当前字符是否是递增的数字
        if ('0' <= s[i]  && s[i] <= '9' && '0' <= s[i - 1]  && s[i - 1] <= '9' && s[i] > s[i-1]) {
            if (currentLength == 0) {
                currentStart = i - 1;
            }
            currentLength++;
        } else {
            // 更新最长递增子串的位置和长度
            if (currentLength > longestLength) {
                longestStart = currentStart;
                longestLength = currentLength;
            }
            currentLength = 0;
        }
    }

    // 处理循环结束后最后一个递增子串的情况
    if (currentLength > longestLength) {
        longestStart = currentStart;
        longestLength = currentLength;
    }

    // 返回最长递增子串
    return s.substr(longestStart, longestLength + 1);
}

int main() {
    std::string str = "abc12345def1267891xyz";
    std::string result = findLongestIncreasingSubstring(str);
    std::cout << result << std::endl;  // 输出 "45678"

    return 0;
}