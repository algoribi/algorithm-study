#include <algorithm>
#include <iostream>
#include <vector>

#define INF 100000000
using namespace std;

int main() {
    int ans[55][55] = {0};
    int n, a, b;
    cin >> n;
    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        ans[a][b] = 1;
        ans[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && ans[i][j] == 0)
                ans[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (ans[j][i] + ans[i][k] < ans[j][k])
                    ans[j][k] = ans[j][i] + ans[i][k];
            }
        }
    }

    int minnum = INF, p[55] = {0}, counter = 0;
    for (int i = 1; i <= n; i++) {
        int maxnum = 0;
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] > maxnum)
                maxnum = ans[i][j];
        }
        p[i] = maxnum;
        if (maxnum < minnum) {
            minnum = maxnum;
            counter = 1;
        } else if (maxnum == minnum)
            counter++;
    }
    cout << minnum << " " << counter << "\n";
    for (int i = 1; i <= n; i++) {
        if (p[i] == minnum)
            cout << i << " ";
    }
    return 0;
}