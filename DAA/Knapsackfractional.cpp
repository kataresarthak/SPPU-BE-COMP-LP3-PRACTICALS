#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];
    return a1 > b1;
}

double fractionalKnapsack(vector<int>& values, vector<int>& weights, int C) {
    int n = values.size();
    vector<vector<int>> items(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        items[i][0] = values[i];
        items[i][1] = weights[i];
    }
    sort(items.begin(), items.end(), compare);
    double result = 0.0;
    int currentCapacity = C;
    for (int i = 0; i < n; i++) {
        if (items[i][1] <= currentCapacity) {
            result += items[i][0];
            currentCapacity -= items[i][1];
        }
        else {
            result += (1.0 * items[i][0] / items[i][1]) * currentCapacity;
            break; 
        }
    }
    return result;
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int C = 50;

    double maxValue = fractionalKnapsack(values, weights, C);
    cout << "MAXIMUM VALUE IN KNAPSACK: " << maxValue << endl;
    return 0;
}
