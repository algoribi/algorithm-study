#include <iostream>
#include <algorithm>

using namespace std;

string s1, s2;
int dp[1005][1005] = {0};
int rec(int p1, int p2){
    if (p1 >= s1.size() || p2 >= s2.size())
        return 0;
    if (dp[p1][p2] != -1)
        return dp[p1][p2];
    if (s1[p1] == s2[p2])
        return dp[p1][p2] = 1 + rec(p1 + 1, p2 + 1);
    else
        return dp[p1][p2] = max(rec(p1 + 1, p2), rec(p1, p2 + 1));
}

int main() {
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++)
            dp[i][j] = -1;
    }
    cout << rec(0, 0);
    return 0;
}