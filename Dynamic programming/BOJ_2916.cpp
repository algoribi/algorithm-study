// algorithm study
// BOJ_2916_자와 각도기

#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int chk[360] = {0};
    chk[0] = 1;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < 360; j++) {
            if (chk[j] == 0)
                continue;
            for (int k = 1; k < 360; k++) {
                chk[(j + (k * num)) % 360] = 1;
                chk[abs((j - (k * num)) % 360)] = 1;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        if (chk[temp] == 1)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
    return 0;
}