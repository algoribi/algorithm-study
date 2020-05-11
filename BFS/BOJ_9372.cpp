// algorithm study
// BOJ_9372_상근이의 여행

#include <iostream>

using namespace std;

int main(void) {
    int t, n, m, a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            cin >> a >> b;
        }
        cout << n - 1 << endl;
    }
    return 0;
}