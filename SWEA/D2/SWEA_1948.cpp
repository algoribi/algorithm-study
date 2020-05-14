// algorithm study
// SWEA_[D2]1948_날짜 계산기

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < t; i++) {
        int am, ad, bm, bd, answer = 0;
        cin >> am >> ad >> bm >> bd;
        for (int j = am; j < bm; j++) {
            answer += (month[j - 1]);
        }
        answer -= (ad - bd);
        cout << "#" << i + 1 << " " << answer + 1 << "\n";
    }
    return 0;
}