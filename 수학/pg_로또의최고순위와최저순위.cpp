#include <iostream>
#include <set>
#include <vector>

#define endl "\n"

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> lot;
    int rank[] = {6, 6, 5, 4, 3, 2, 1};
    int zero = 0, counter = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0)
            zero++;
        else
            lot.insert(lottos[i]);
    }
    for (int i = 0; i < win_nums.size(); i++) {
        if (lot.find(win_nums[i]) != lot.end())
            counter++;
    }
    answer.push_back(rank[counter + zero]);
    answer.push_back(rank[counter]);
    return answer;
}

int main() {
    vector<int> lottos = {44, 1, 0, 0, 31, 25};
    vector<int> win_nums = {31, 10, 45, 1, 6, 19};
    vector<int> ans = solution(lottos, win_nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";
    return 0;
}