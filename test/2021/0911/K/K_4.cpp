#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

int apeach[15], max_score = 0;
vector<int> answer;
void dfs(int arrow, int score, int sum, int a_sum, int save[15]) {
    if (score > 10) {
        if (sum > a_sum && sum - a_sum > max_score) {
            max_score = sum - a_sum;
            answer.clear();
            for (int i = 10; i >= 0; i--)
                answer.push_back(save[i]);
        }
        return;
    }
    for (int i = arrow; i >= 0; i--) {
        save[score] += i;
        if (apeach[score] < save[score])
            sum += score;
        else if (apeach[score] != 0)
            a_sum += score;
        dfs(arrow - i, score + 1, sum, a_sum, save);
        if (apeach[score] < save[score])
            sum -= score;
        else if (apeach[score] != 0)
            a_sum -= score;
        save[score] -= i;
    }
}

vector<int> solution(int n, vector<int> info) {
    int num = 10, save[15] = {0};
    for (int i = 0; i < 11; i++)
        apeach[num--] = info[i];
    dfs(n, 0, 0, 0, save);
    if (max_score == 0)
        answer.push_back(-1);
    return answer;
}

int main() {
    int n = 5;
    vector<int> info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    vector<int> a = solution(n, info);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
}