
#include <iostream>
#include <vector>
#include <algorithm>

int getMinSteps(int n) {
    std::vector<int> dp(n + 1);
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];

        if (i % 2 == 0) {
            dp[i] = std::min(dp[i], 1 + dp[i / 2]);
        }

        if (i % 3 == 0) {
            dp[i] = std::min(dp[i], 1 + dp[i / 3]);
        }
    }

    return dp[n];
}

int main() {
    int n;

    std::cout << "Enter a value: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Please enter a positive integer.\n";
        return 1;
    }

    std::cout << "Minimum number of steps required: "
              << getMinSteps(n) << '\n';

    return 0;
}
