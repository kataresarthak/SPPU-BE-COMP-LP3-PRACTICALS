#include<iostream>
#include<cmath>
using namespace std;

int x[20], count = 1;
bool place(int r, int c) {
    for (int i = 1; i < r; i++) {
        if (x[i] == c || abs(x[i] - c) == abs(i - r))
            return false;
    }
    return true;
}

void NQueen(int r, int n) {
    if (r > n) {
        cout << "\n\nSOLUTION: " << count++ << "\n\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << (x[i] == j ? " Q " : " - ");
            cout << endl;
        }
    }
    else {
        for (int c = 1; c <= n; c++) {
            if (place(r, c)) { 
                x[r] = c;       
                NQueen(r + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cout << "ENTER THE NUMBER OF QUEEN'S: ";
    cin >> n;
    NQueen(1, n);
    return 0;
}
