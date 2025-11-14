#include <iostream>
#include <vector>
using namespace std;

int Knapsack(const vector<int>& values, const vector<int>& weights, int C) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= C; w++) { 
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else 
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][C];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int C = 50;

    int maxValue = Knapsack(values, weights, C);
    cout << "MAXIMUM VALUE IN KNAPSACK: " << maxValue << endl;
    return 0;
}
