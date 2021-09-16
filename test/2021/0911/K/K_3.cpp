#include <iostream>
#include <map>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

struct save {
    int chk, temp, sum;
};

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, save> m;
    for (int i = 0; i < records.size(); i++) {
        int num = stoi(records[i].substr(6, 4));
        int time = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2));
        if (m.find(num) == m.end())
            m.insert({num, {1, time, 0}});
        else {
            if (m[num].chk == 1) {
                m[num].chk = 0;
                m[num].sum += time - m[num].temp;
            } else {
                m[num].chk = 1;
                m[num].temp = time;
            }
        }
    }
    int chk_out = 1439;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second.chk == 1)
            it->second.sum += chk_out - it->second.temp;
        int pay = fees[1];
        it->second.sum -= fees[0];
        if (it->second.sum <= 0)
            answer.push_back(pay);
        else {
            pay += (int)(it->second.sum / fees[2]) * fees[3];
            if (it->second.sum % fees[2] > 0)
                pay += fees[3];
            answer.push_back(pay);
        }
    }
    return answer;
}

int main() {
    vector<int> fees = {1, 461, 1, 10};
    vector<string> records = {"00:00 1234 IN"};
    vector<int> ans = solution(fees, records);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}