// algorithm study
// SWEA_[D2]1946_간단한 압축 풀기

#include <iostream>

using namespace std;

int main() {
    int test_case, n;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        cin >> n;
        int counter = 0;
        cout << "#" << t + 1 << "\n";
        for (int i = 0; i < n; i++) {
            char c;
            int num;
            cin >> c >> num;
            for (int k = 0; k < num; k++) {
                if (counter == 10) {
                    cout << "\n";
                    counter = 0;
                }
                cout << c;
                counter++;
            }
        }
        cout << "\n";
    }
    return 0;
}