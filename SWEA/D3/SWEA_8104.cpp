// algorithm study
// SWEA_[D3]8104_조 만들기

#include <iostream>

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        int n, k, answer[21] = {0}, count = 1, chk = 0;
        cin >> n >> k;
        for (int i = 1; i <= n * k; i++) {
            answer[count] += i;
            if (chk == 0) {
                if (count == k)
                    chk = 1;
                else
                    count++;
            } else {
                if (count == 1)
                    chk = 0;
                else
                    count--;
            }
        }
        cout << "#" << t + 1 << " ";
        for (int i = 1; i <= k; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}