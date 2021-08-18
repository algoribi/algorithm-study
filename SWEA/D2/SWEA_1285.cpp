#include <iostream>
#define endl "\n"

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    for (int t = 1; t <= test_case; t++) {
        int n, ans = 100001, counter = 0, num;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (num < 0)
                num = -num;
            if (ans > num) {
                counter = 1;
                ans = num;
            } else if (ans == num)
                counter++;
        }
        cout << "#" << t << " " << ans << " " << counter << " " << endl;
    }
}