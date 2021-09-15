#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

struct cost {
    string s;
    float d;
    int i;
};

bool cmp(const cost& c1, const cost& c2) {
    if (c1.d == c2.d) {
        if (c1.i == c2.i)
            return c1.s < c2.s;  // 사전순
        return c1.i > c2.i;
    }
    return c1.d > c2.d;
}

vector<string> solution(vector<string> records, int k, string date) {
    vector<string> answer;
    map<string, map<string, int>> m;
    int fl = stoi(date.substr(0, 4)) * 12 * 30 + stoi(date.substr(5, 2)) * 30 + stoi(date.substr(8, 2));
    for (int i = 0; i < records.size(); i++) {
        int d = stoi(records[i].substr(0, 4)) * 12 * 30 + stoi(records[i].substr(5, 2)) * 30 + stoi(records[i].substr(8, 2));
        if (d <= fl && d >= fl - 9) {
            string pid_name = records[i].substr(16, 4);
            string uid_name = records[i].substr(11, 4);
            map<string, int> t;
            if (m.find(pid_name) == m.end())
                m.insert({pid_name, t});
            if (m[pid_name].find(uid_name) == m[pid_name].end())
                m[pid_name].insert({uid_name, 1});
            else
                m[pid_name][uid_name]++;
        } else if (d > fl)
            break;
    }
    vector<cost> ans;
    for (auto it = m.begin(); it != m.end(); it++) {
        int counter1 = 0, counter2 = 0;
        for (auto iter = m[it->first].begin(); iter != m[it->first].end(); iter++) {
            counter2 += iter->second;
            if (iter->second >= 2)
                counter1++;
        }
        cost c;
        c.s = it->first;
        c.d = (float)(counter1 / it->second.size()) * 100;
        c.i = counter2;
        ans.push_back(c);
    }
    sort(ans.begin(), ans.end(), cmp);
    if (ans.size() == 0)
        answer.push_back("no result");
    else {
        for (int i = 0; i < ans.size(); i++)
            answer.push_back(ans[i].s);
    }
    return answer;
}

int main() {
    //vector<string> records = {"2020-02-02 uid1 pid1", "2020-02-26 uid1 pid1", "2020-02-26 uid2 pid1", "2020-02-27 uid3 pid2", "2020-02-28 uid4 pid2", "2020-02-29 uid3 pid3", "2020-03-01 uid4 pid3", "2020-03-03 uid1 pid1", "2020-03-04 uid2 pid1", "2020-03-05 uid3 pid2", "2020-03-05 uid3 pid3", "2020-03-05 uid3 pid3", "2020-03-06 uid1 pid4"};
    vector<string> records = {"2020-02-02 uid141 pid141", "2020-02-03 uid141 pid32", "2020-02-04 uid32 pid32", "2020-02-05 uid32 pid141"};
    int k = 10;
    string date = "2020-02-05";
    vector<string> a = solution(records, k, date);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}