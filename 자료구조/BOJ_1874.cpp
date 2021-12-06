#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, a, chk = 1;
    vector<int> v;
    vector<char> ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (v.size() == 0 || v[v.size() - 1] != a) {
            if (chk > a) {
                cout << "NO";
                return 0;
            }
            while (chk != a) {
                v.push_back(chk);
                ans.push_back('+');
                chk++;
            }
            ans.push_back('+');
            ans.push_back('-');
            chk++;
        } else if (v[v.size() - 1] == a) {
            v.pop_back();
            ans.push_back('-');
        }
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
    return 0;
}