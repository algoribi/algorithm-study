#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> number;
    for (int i = 0; i < id_list.size(); i++)
        number[id_list[i]] = 0;
    map<string, set<string>> m;
    for (int i = 0; i < report.size(); i++) {
        int find_num = report[i].find(" ");
        string s1 = report[i].substr(0, find_num);
        string s2 = report[i].substr(find_num + 1, report[i].size() - find_num);
        if (m.find(s1) == m.end()) {
            m.insert({s1, {s2}});
            number[s2]++;
        } else {
            if (m[s1].find(s2) == m[s1].end()) {
                m[s1].insert(s2);
                number[s2]++;
            }
        }
    }
    for (int i = 0; i < id_list.size(); i++) {
        int counter = 0;
        for (auto it = m[id_list[i]].begin(); it != m[id_list[i]].end(); it++) {
            if (number[*it] >= k)
                counter++;
        }
        answer.push_back(counter);
    }
    return answer;
}
int main() {
    vector<string> id_list = {"con", "ryan"};
    vector<string> report = {"ryan con", "ryan con", "ryan con", "ryan con"};
    int k = 3;
    vector<int> a = solution(id_list, report, k);
}