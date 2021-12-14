#include <iostream>

using namespace std;

int bee[700 * 700];

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int m, n, a, b, c;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        for (int j = a; j < a + b; j++) 
            bee[j]++;
        for (int j = a + b; j < a + b + c; j++)
            bee[j] += 2;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0)
                cout << bee[m - 1 - i] + 1 << " ";
            else
                cout << bee[m - 1 + j] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}