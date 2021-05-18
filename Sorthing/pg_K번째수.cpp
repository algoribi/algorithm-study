#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans(vector<int> array, int a, int b, int c) {
    array.erase(array.begin() + b, array.begin() + array.size());
    array.erase(array.begin(), array.begin() + a - 1);
    sort(array.begin(), array.end());
    return array[c - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
        answer.push_back(ans(array, commands[i][0], commands[i][1], commands[i][2]));
    return answer;
}