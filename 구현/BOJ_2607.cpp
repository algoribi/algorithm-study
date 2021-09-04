#include <iostream>
#define endl "\n"

using namespace std;

int main() {
    int n, eng[30] = {0}, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++)
        eng[s[i] - 'A']++;
    for (int i = 0; i < n - 1; i++) {
        string t;
        cin >> t;
        int chk = 0, t_eng[30] = {0};
        for (int j = 0; j < t.size(); j++)
            t_eng[t[j] - 'A']++;
        for (int j = 0; j < 30; j++) {
            if (eng[j] > t_eng[j])
                chk += eng[j] - t_eng[j];
            else if (eng[j] < t_eng[j])
                chk += t_eng[j] - eng[j];
        }
        if (s.size() == t.size() && chk <= 2)
            ans++;
        else if (s.size() != t.size() && chk <= 1)
            ans++;
    }
    cout << ans;
}