
#include <iostream>
#include <vector>
#include <algorithm>

int getMinSteps(int n, std::vector<int>& memo) {
    if (n == 1) {
        return 0;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    int result = 1 + getMinSteps(n - 1, memo);

    if (n % 2 == 0) {
        result = std::min(result, 1 + getMinSteps(n / 2, memo));
    }

    if (n % 3 == 0) {
        result = std::min(result, 1 + getMinSteps(n / 3, memo));
    }

    memo[n] = result;
    return result;
}

int main() {
    int n;

    std::cout << "Enter a value: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Please enter a positive integer.\n";
        return 1;
    }

    std::vector<int> memo(n + 1, -1);

    std::cout << "Minimum number of steps of required: "
              << getMinSteps(n, memo) << '\n';

    return 0;
}
