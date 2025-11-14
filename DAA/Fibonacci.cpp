#include <iostream>
using namespace std;

void fibNR(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int temp = a + b;
        a = b;
        b = temp;
    }
}
// Time Complexity = O(n)
// Space Complexity = O(1)

int fibR(int n) {
    if (n <= 1)
        return n;
    return fibR(n - 1) + fibR(n - 2);
}
// Time Complexity = O(2^n)
// Space Complexity = O(n)

int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    cout << "Fibonacci Series (Non-Recursive): ";
    fibNR(n);
    cout << "\nFibonacci Series (Recursive): ";
    for (int i = 0; i < n; i++) {
        cout << fibR(i) << " ";
    }
    return 0;
}
