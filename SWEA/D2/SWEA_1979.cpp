#include <iostream>
#define endl "\n"

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    for (int t = 1; t <= test_case; t++) {
        int n, k, map[20][20], ans = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int counter = 0;
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
                if (map[i][j] == 1)
                    counter++;
                else if (map[i][j] == 0 && counter == k) {
                    ans++;
                    counter = 0;
                } else 
                    counter = 0;
            }
            if (counter == k)
                ans++;
        }
        for (int i = 1; i <= n; i++) {
            int counter = 0;
            for (int j = 1; j <= n; j++) {
                if (map[j][i] == 1)
                    counter++;
                else if (map[j][i] == 0 && counter == k) {
                    ans++;
                    counter = 0;
                } else 
                    counter = 0;
            }
            if (counter == k)
                ans++;
        }
        cout << "#" << t << " " << ans << endl;
    }
}