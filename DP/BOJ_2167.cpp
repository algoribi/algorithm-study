// algorithm study
// BOJ_2163_2차원 배열의 합

#include <iostream>

using namespace std;

int v[305][305];
void ans(int a, int b, int c, int d) {
    int an = 0;
    for (int i = a; i <= c; i++) {
        for (int j = b; j <= d; j++) {
            an += v[i][j];
        }
    }
    cout << an << '\n';
}

int main() {
    int n, m, k;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ans(a, b, c, d);
    }
    return 0;
}