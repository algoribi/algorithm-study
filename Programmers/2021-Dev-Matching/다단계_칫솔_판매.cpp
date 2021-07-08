#include <iostream>
#include <map>
#include <vector>

#define endl "\n"

using namespace std;

vector<int> member[10010], answer, zero;
map<string, int> m;
map<int, vector<int>> sell;
int number;

vector<int> dfs(int x) {
    vector<int> re;
    for (int i = 0; i < member[x].size(); i++) {
        vector<int> add = dfs(member[x][i]);
        for (int j = 0; j < add.size(); j++) {
            re.push_back(add[j] / 10);
            answer[x] += add[j] - add[j] / 10;
        }
    }
    if (sell.find(x) != sell.end()) {
        for (int i = 0; i < sell[x].size(); i++) {
            re.push_back(sell[x][i] / 10);
            answer[x] += sell[x][i] - re[re.size() - 1];
        }
    }
    return re;
}

void sol(int x) {
    for (int i = 0; i < zero.size(); i++)
        dfs(zero[i]);
    return;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    number = enroll.size();
    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(0);
        m[enroll[i]] = i;
        if (referral[i] == "-")
            zero.push_back(i);
        else
            member[m[referral[i]]].push_back(i);
    }
    for (int i = 0; i < seller.size(); i++)
        sell[m[seller[i]]].push_back(amount[i] * 100);
    sol(0);
    return answer;
}

int main() {
    vector<string> enroll = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> referral = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> seller = {"young", "john", "tod", "emily", "mary", "tod"};
    vector<int> amount = {12, 4, 2, 5, 10, 2};
    vector<int> ans = solution(enroll, referral, seller, amount);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";
    return 0;
}