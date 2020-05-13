// algorithm study
// SWEA_[D3]7853_오타

#include <iostream>
#include <vector>.

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        string s;
        cin >> s;
        long long answer = 1, chk = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                if (s[i] == s[i + 1])
                    chk = 1;
                else
                    chk = 2;
            } else if (i == s.size() - 1) {
                if (s[i - 1] == s[i])
                    chk = 1;
                else
                    chk = 2;
            } else {
                if (s[i - 1] == s[i] && s[i] == s[i + 1] && s[i - 1] == s[i + 1])
                    chk = 1;
                else if (s[i - 1] == s[i] || s[i] == s[i + 1] || s[i - 1] == s[i + 1])
                    chk = 2;
                else
                    chk = 3;
            }
            answer *= chk;
            answer %= 1000000007;
        }
        cout << "#" << t + 1 << " " << answer << "\n";
    }
    return 0;
}