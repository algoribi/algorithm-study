#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int solution(string str1, string str2) {
    map<string, int> m1, m2;
    int mcount1 = 0, mcount2 = 0;
    for (int i = 0; i < str1.size() - 1; i++) {
        if (tolower(str1[i]) < 'a' || tolower(str1[i]) > 'z' || str1[i] == ' ' || tolower(str1[i + 1]) < 'a' || tolower(str1[i + 1]) > 'z' || str1[i + 1] == ' ')
            continue;
        string temp;
        temp.push_back(tolower(str1[i]));
        temp.push_back(tolower(str1[i + 1]));
        if (m1.find(temp) == m1.end()) {
            m1.insert(make_pair(temp, 1));
        } else {
            m1[temp]++;
            mcount1++;
        }
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (tolower(str2[i]) < 'a' || tolower(str2[i]) > 'z' || str2[i] == ' ' || tolower(str2[i + 1]) < 'a' || tolower(str2[i + 1]) > 'z' || str2[i + 1] == ' ')
            continue;
        string temp;
        temp.push_back(tolower(str2[i]));
        temp.push_back(tolower(str2[i + 1]));
        if (m2.find(temp) == m2.end()) {
            m2.insert(make_pair(temp, 1));
        } else {
            m2[temp]++;
            mcount2++;
        }
    }
    if (m1.empty() && m2.empty())
        return 65536;
    double uni = 0, inter = 0;
    for (auto it = m1.begin(); it != m1.end(); it++) {
        if (m2.find(it->first) == m2.end())
            continue;
        inter += min(m2[it->first], it->second);
    }
    uni = m1.size() + m2.size() + mcount1 + mcount2 - inter;
    double answer = inter / uni * 65536;
    int an = answer / 1;
    return an;
}