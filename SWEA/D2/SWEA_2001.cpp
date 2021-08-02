#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        int n, m, arr[20][20], maxNum = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                if (i >= m - 1 && j >= m - 1) {
                    int add = 0;
                    for (int a = i; a > i - m; a--) {
                        for (int b = j; b > j - m; b--)
                            add += arr[a][b];
                    }
                    if (add > maxNum)
                        maxNum = add;
                }
            }
        }
        cout << "#" << t << " " << maxNum << endl;
    }
    return 0;
}