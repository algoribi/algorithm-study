// 세 친구
#include <iostream>

using namespace std;

int f[4010][4010];
int have_f[4010];

int main() {
    int n, m, a, b, counter, answer = -1;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; 
        f[a][b] = 1;
        f[b][a] = 1;
        have_f[a]++;
        have_f[b]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (f[i][j] == 1) {
                for (int k = 1; k <= n; k++) {
                    if (f[j][k] == 1 && f[i][k] == 1) {
                        counter = have_f[i] + have_f[j] + have_f[k] - 6;
                        if (answer == -1 || counter < answer)
                            answer = counter;
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}