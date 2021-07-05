#include <iostream>

using namespace std;

int n, k, ice[1000005] = {0}, a, b, counter = 0, ans = 0, chk = 0;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ice[b] = a;
        if (chk < b)
            chk = b;
    }
    for (int i = 0; i <= chk; i++) {
        if (i > k * 2)
            counter -= ice[i - (k * 2 + 1)];
        counter += ice[i];
        if (ans < counter)
            ans = counter;
    }
    cout << ans;

    return 0;
}