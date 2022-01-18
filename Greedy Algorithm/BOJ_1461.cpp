#include <iostream>
#include <algorithm>

using namespace std;

int n, m, t, mp = 0, p = 0, fl = 0, ans = 0, mbook[55], book[55];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < 0)
            mbook[mp++] = t;
        else
            book[p++] = -t;
    }
    sort(mbook, mbook + mp);
    sort(book, book + p);

    while (1) {
        if (fl < mp)
            ans += (-1 * mbook[fl]) * 2;
        else
            break;
        fl += m;
    } 
    fl = 0;
    while (1) {
        if (fl < p)
            ans += (-1 * book[fl]) * 2;
        else
            break;
        fl += m;
    }
    ans -= max(-1 * book[0], -1 * mbook[0]);
    cout << ans;
    return 0;
}