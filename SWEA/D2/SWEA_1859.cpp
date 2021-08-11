#include <iostream>
#include <vector>

#define endl "\n"
using namespace std;

int main() {
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        int n;
        cin >>n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        long long ans = 0;
        int chk = 0;
        for (int i = v.size() - 1 ; i >= 0; i--) {
            if (v[i] > chk) {
                chk = v[i];
                continue;
            } else
                ans += chk - v[i];

        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}