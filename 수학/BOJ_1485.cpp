// algorithm study
// BOJ_1485_정사각형

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        pair<int, int> x[5];
        for (int j = 0; j < 4; j++) {
            cin >> x[j].first >> x[j].second;
        }
        int save[10], count = 0;
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                save[count] = ((x[j].first - x[k].first) * (x[j].first - x[k].first)) + ((x[j].second - x[k].second) * (x[j].second - x[k].second));
                count++;
            }
        }
        sort(save, save + 6);
        if (save[0] == save[1] && save[1] == save[2] && save[2] == save[3] && save[3] == save[0] && save[4] == save[5])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}