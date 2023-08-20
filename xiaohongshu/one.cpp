#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> words;
    for (int i = 0; i < n; ++i) {
        std::string cur;
        std::cin >> cur;
        words.push_back(cur);
    }

    std::unordered_map<std::string, int> hash_str;
    int renum = 0;
    int re_words = 0;
    std::unordered_set<std::string> visited;

    for (int i = 0; i < n; ++i) {
        hash_str[words[i]] += 1;
        if (visited.find(words[i]) == visited.end() && hash_str[words[i]] > renum) {
            renum += 1;
            re_words += 1;
            visited.insert(words[i]);
        }
    }

    std::cout << re_words << std::endl;

    return 0;
}
