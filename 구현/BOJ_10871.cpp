// BOJ_10871_X보다 작은 수

#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t < x)
            cout << t << " ";
    }
    return 0;
}