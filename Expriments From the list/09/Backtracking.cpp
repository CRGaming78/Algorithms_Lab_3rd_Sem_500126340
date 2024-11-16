// Aim: Compare the Backtracking and Branch & Bound Approach by the implementation of 0/1 Knapsack problem. Also compare the performance with dynamic programming approach.
#include <iostream>
#include <vector>
using namespace std;
int maxProfit = 0;

void knapsackBacktracking(vector<int> &weights, vector<int> &values, int W, int index, int currentProfit, int currentWeight) {
    if (currentWeight > W || index == weights.size()) {
        return;
    }
    // Update the maximum profit
    maxProfit = max(maxProfit, currentProfit);
    // Include the current item
    knapsackBacktracking(weights, values, W, index + 1, currentProfit + values[index], currentWeight + weights[index]);
    // Exclude the current item
    knapsackBacktracking(weights, values, W, index + 1, currentProfit, currentWeight);
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
    knapsackBacktracking(weights, values, W, 0, 0, 0);
    cout << "Maximum Profit (Backtracking): " << maxProfit << endl;
    return 0;
}