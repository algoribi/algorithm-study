#include <iostream>

using namespace std;

string s1, s2;
int dp[4010][4010] = {0}, ans = 0;

int main() {
    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] != s2[j])
                continue;
            if ((i == 0 || j == 0))
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
            if (ans < dp[i][j])
                ans = dp[i][j];
        }
    }
    cout << ans;
    return 0;
}