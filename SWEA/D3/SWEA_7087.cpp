// algorithm study
// SWEA_[D3]7087_문제 제목 붙이기

#include <iostream>

using namespace std;

int main() {
    int test_case, n;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        cin >> n;
        int eng[30] = {0}, count = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            eng[s[0] - 'A']++;
        }
        for (int i = 0; i < 30; i++) {
            if (eng[i] == 0)
                break;
            count++;
        }
        cout << "#" << t + 1 << " " << count << "\n";
    }
    return 0;
}