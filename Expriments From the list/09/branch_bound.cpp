#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int level;
    int profit;
    int weight;
    double bound;
};

struct Compare {
    bool operator()(Node a, Node b) {
        return a.bound < b.bound;
    }
};

double calculateBound(Node u, int n, int W, vector<int> &weights, vector<int> &values) {
    if (u.weight >= W) return 0;
    double bound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;
    while (j < n && totalWeight + weights[j] <= W) {
        totalWeight += weights[j];
        bound += values[j];
        j++;
    }
    if (j < n) {
        bound += (W - totalWeight) * ((double)values[j] / weights[j]);
    }
    return bound;
}

int knapsackBranchAndBound(int n, int W, vector<int> &weights, vector<int> &values) {
    priority_queue<Node, vector<Node>, Compare> pq;
    Node u, v;
    u.level = -1; u.profit = 0; u.weight = 0; u.bound = calculateBound(u, n, W, weights, values);
    pq.push(u);
    int maxProfit = 0;
    while (!pq.empty()) {
        u = pq.top();
        pq.pop();
        if (u.bound > maxProfit && u.level < n - 1) {
            v.level = u.level + 1;
            v.weight = u.weight + weights[v.level];
            v.profit = u.profit + values[v.level];
            v.bound = calculateBound(v, n, W, weights, values);

            if (v.weight <= W && v.profit > maxProfit) {
                maxProfit = v.profit;
            }
            if (v.bound > maxProfit) {
                pq.push(v);
            }
            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = calculateBound(v, n, W, weights, values);
            if (v.bound > maxProfit) {
                pq.push(v);
            }
        }
    }
    return maxProfit;
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
    cout << "Maximum Profit (Branch & Bound): " << knapsackBranchAndBound(n, W, weights, values) << endl;
    return 0;
}