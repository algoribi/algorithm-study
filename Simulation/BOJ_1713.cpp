// algorithm study
// BOJ_1713 후보 추천하기

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int chk[110][2] = {0};

bool v_sort(int a, int b) {
    if (chk[a][0] == chk[b][0])
        return chk[a][1] > chk[b][1];
    return chk[a][0] > chk[b][0];
}

int main() {
    int n, m, time = 0, f[110] = {0};
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        chk[num][0]++;
        if (f[num] == 0) {
            if (v.size() == n) {
                sort(v.begin(), v.end(), v_sort);
                f[v[v.size() - 1]] = 0;
                chk[v[v.size() - 1]][0] = 0;
                v.pop_back();
            }
            v.push_back(num);
            chk[num][1] = time;
            f[num] = 1;
        }
        time++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}