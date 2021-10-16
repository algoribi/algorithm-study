#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long time_stamp[360010] = {0};

string solution(string play_time, string adv_time, vector<string> logs) {
    int plays = (play_time[0] - '0') * 36000 + (play_time[1] - '0') * 3600 + (play_time[3] - '0') * 600 + (play_time[4] - '0') * 60 + (play_time[6] - '0') * 10 + (play_time[7] - '0');
    int advs = (adv_time[0] - '0') * 36000 + (adv_time[1] - '0') * 3600 + (adv_time[3] - '0') * 600 + (adv_time[4] - '0') * 60 + (adv_time[6] - '0') * 10 + (adv_time[7] - '0');
    if (plays == advs)
        return "00:00:00";
    for (int i = 0; i < logs.size(); i++) {
        int start_p = (logs[i][0] - '0') * 36000 + (logs[i][1] - '0') * 3600 + (logs[i][3] - '0') * 600 + (logs[i][4] - '0') * 60 + (logs[i][6] - '0') * 10 + (logs[i][7] - '0');
        int end_p = (logs[i][9] - '0') * 36000 + (logs[i][10] - '0') * 3600 + (logs[i][12] - '0') * 600 + (logs[i][13] - '0') * 60 + (logs[i][15] - '0') * 10 + (logs[i][16] - '0');
        time_stamp[start_p] += 1;
        time_stamp[end_p] -= 1;
    }

    for (int i = 1; i < plays; i++)
        time_stamp[i] += time_stamp[i - 1];
    for (int i = 1; i < plays; i++)
        time_stamp[i] += time_stamp[i - 1];

    long long sum = time_stamp[advs];
    int save = 0;
    for (int i = advs + 1; i < plays; i++) {
        long long add = time_stamp[i] - time_stamp[i - advs];
        if (add > sum) {
            sum = add;
            save = i - advs + 1;
        }
    }
    int H1 = save / 36000;
    int H2 = (save % 36000) / 3600;
    int M1 = ((save % 36000) % 3600) / 600;
    int M2 = (((save % 36000) % 3600) % 600) / 60;
    int S1 = ((((save % 36000) % 3600) % 600) % 60) / 10;
    int S2 = ((((save % 36000) % 3600) % 600) % 60) % 10;
    string answer = to_string(H1) + to_string(H2) + ':' + to_string(M1) + to_string(M2) + ':' + to_string(S1) + to_string(S2);

    return answer;
}
int main() {
    string play_time = "99:59:59";
    string adv_time = "25:00:00";
    vector<string> logs = {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"};
    string ans = solution(play_time, adv_time, logs);
    cout << ans << "\n";
    return 0;
}