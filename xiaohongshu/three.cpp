#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    std::vector<std::vector<int>> roads(m, std::vector<int>(3));
    for (int i = 0; i < m; ++i) {
        std::cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, -1e9));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= h[i - 1]) {
                for (int x = i - 1; x >= 0; --x) {
                    int prev_value = dp[x][j - h[i - 1]];
                    if (prev_value != -1e9) {
                        int curr_value = prev_value + a[i - 1];
                        int curr_time = j - h[i - 1] + roads[x][2];
                        if (curr_time <= k) {
                            dp[i][j] = std::max(dp[i][j], curr_value);
                        }
                    }
                }
            }
        }
    }

    int max_value = *std::max_element(dp[n].begin(), dp[n].end());
    std::cout << max_value << std::endl;

    return 0;
}
