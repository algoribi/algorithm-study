// algorithm study
// BOJ_6359_만취한 상범

#include <iostream>

using namespace std;

int main() {
    int t, room[105];
    cin >> t;

    while (t != 0) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1 * i; j <= n; j = j + i) {
                if (room[j] == 1)
                    room[j] = 0;
                else if (room[j] == 0)
                    room[j] = 1;
            }
        }
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (room[i] == 1) {
                count++;
                room[i] = 0;
            }
        }
        cout << count << '\n';
        t--;
    }
    return 0;
}