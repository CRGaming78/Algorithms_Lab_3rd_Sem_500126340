#include <iostream>
#include <vector>
using namespace std;

int knapsackDP(int W, vector<int> &weights, vector<int> &values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the weight capacity of the knapsack: ";
    cin >> W;
    vector<int> weights(n), values(n);
    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    cout << "Maximum Profit (DP): " << knapsackDP(W, weights, values) << endl;
    return 0;
}