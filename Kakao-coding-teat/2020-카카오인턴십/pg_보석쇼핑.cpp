#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 0};
    map<string, int> m;
    int start = 0, counter = 0;
    for (int i = 0; i < gems.size(); i++) {
        if (m.find(gems[i]) != m.end())
            m.find(gems[i])->second += 1;
        else
            m.insert(make_pair(gems[i], 1));

        while (m.find(gems[start])->second > 1) {
            m.find(gems[start])->second -= 1;
            start++;
        }
        if (counter == 0 || counter < m.size() || answer[1] - answer[0] > i - start) {
            answer[0] = start;
            answer[1] = i;
            counter = m.size();
        }
    }
    answer[0]++;
    answer[1]++;
    return answer;
}