#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    int n, start = 0;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        long long ans = 0, multi = 1, counter;
        if (t == "char")
            counter = 2;
        else if (t == "int")
            counter = 8;
        else if (t == "long_long")
            counter = 16;
        for (int j = counter + start - 1; j >= start; j--) {
            long long num;
            if (s[j] >= '0' && s[j] <= '9')
                num = s[j] - '0';
            else
                num = s[j] - 'a' + 10;
            if (num != 0)
                ans += num * multi;
            multi *= 16;
        }
        start += counter;
        cout << ans << " ";
    }
    return 0;
}