// algorithm study
// SWEA_[D3]7732_시간 개념

#include <iostream>

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        int h, m, s, now_time = 0, next_time = 0, time[3];
        char c;
        cin >> h >> c >> m >> c >> s;
        now_time += h * 3600 + m * 60 + s;
        cin >> h >> c >> m >> c >> s;
        next_time += h * 3600 + m * 60 + s;
        if (next_time < now_time)
            next_time += 24 * 3600;
        time[0] = (next_time - now_time) / 3600;
        time[1] = ((next_time - now_time) % 3600) / 60;
        time[2] = ((next_time - now_time) % 3600) % 60;
        cout << "#" << t + 1 << " ";
        for (int i = 0; i < 3; i++) {
            if (time[i] < 10)
                cout << 0 << time[i];
            else
                cout << time[i];
            if (i != 2)
                cout << ":";
            else
                cout << "\n";
        }
    }
}