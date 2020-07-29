#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int a, b, c, x, y, ans = 0;
    cin >> a >> b >> c >> x >> y;
    if (x >= y && a > c * 2)
        ans += x * c * 2;
    else if (y >= x && b > c * 2)
        ans += y * c * 2;
    else {
        if (a + b > c * 2) {
            int temp = min(x, y);
            ans += temp * c * 2;
            x -= temp;
            y -= temp;
            ans += x * a + y * b;
        } else
            ans += x * a + y * b;
    }
    cout << ans;
}