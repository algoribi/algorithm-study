// algorithm study
// BOJ_2529_부등호

#include <iostream>
#include <vector>

using namespace std;

int k, cheak[10];
char sign[10];
vector<string> v;
string ans;

void dfs(int t, int count) {
    if (count == k) {
        v.push_back(ans);
        return;
    }
    if (sign[count] == '<') {
        for (int i = 0; i < 10; i++) {
            if (t >= i)
                continue;
            else {
                if (cheak[i] == 0) {
                    cheak[i] = 1;
                    ans.push_back(i + '0');
                    dfs(i, count + 1);
                    cheak[i] = 0;
                    ans.pop_back();
                }
            }
        }
    } else {
        for (int i = 0; i < 10; i++) {
            if (t <= i)
                continue;
            else {
                if (cheak[i] == 0) {
                    cheak[i] = 1;
                    ans.push_back(i + '0');
                    dfs(i, count + 1);
                    cheak[i] = 0;
                    ans.pop_back();
                }
            }
        }
    }
}

int main(void) {
    cin >> k;
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        sign[i] = c;
    }

    for (int i = 0; i < 10; i++) {
        cheak[i] = 1;
        ans.push_back(i + '0');
        dfs(i, 0);
        cheak[i] = 0;
        ans.pop_back();
    }

    cout << v[v.size() - 1] << "\n"
         << v[0] << "\n";

    return 0;
}