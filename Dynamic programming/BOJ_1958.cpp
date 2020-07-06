#include <algorithm>
#include <iostream>

using namespace std;
int lcs[110][110][110] = {0};
int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            for (int k = 1; k <= s3.size(); k++) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                    lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
                else
                    lcs[i][j][k] = max(lcs[i - 1][j][k], max(lcs[i][j - 1][k], lcs[i][j][k - 1]));
            }
        }
    }
    cout << lcs[s1.size()][s2.size()][s3.size()];
    return 0;
}