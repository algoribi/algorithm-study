#include <iostream>
#define endl "\n"

using namespace std;

int main() {
    int t;
    cin >> t;
    int num1[] = {0, 500, 300, 300, 200, 200, 200, 50, 50, 50, 50, 30, 30, 30, 30, 30, 10, 10, 10, 10, 10, 10};
    int num2[] = {0, 512, 256, 256, 128, 128, 128, 128, 64, 64, 64, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32};
    for (int i = 0; i < t; i++) {
        int ans = 0, a, b;
        cin >> a >> b;
        if (a <= 21)
            ans += num1[a];
        if (b <= 31)
            ans += num2[b];
        cout << ans * 10000 << endl;
    }
}