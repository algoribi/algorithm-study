#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct go {
    int point;
    int n = 0;
    int chk = 0;
};

struct cmp {
    bool operator()(go a, go b) {
        if (a.n == b.n)
            return a.chk >= b.chk;
        return a.n < b.n;
    }
};

int main() {
    int testcase;
    cin >> testcase;
    for (int t = 0; t < testcase; t++) {
        int n, m, tt, s, g, h, goal[2010] = {0};
        cin >> n >> m >> tt >> s >> g >> h;
        vector<pair<int, int>> map[2010];
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            map[a].push_back(make_pair(b, d));
            map[b].push_back(make_pair(a, d));
        }
        for (int i = 0; i < tt; i++) {
            int temp;
            cin >> temp;
            goal[temp] = 1;
        }
        priority_queue<go, vector<go>, cmp> q;
        q.push({s, 0, 0});
        int visit[2010] = {0};
        int chk_v[2010] = {0};
        while (!q.empty()) {
            go temp = q.top();
            q.pop();

            if (goal[temp.point] == 1 && temp.chk == 1)
                goal[temp.point] = -1;
            if (temp.chk == 1)
                chk_v[temp.point] = 1;
            int chk = 0;
            for (int i = 0; i < map[temp.point].size(); i++) {
                chk = 0;
                if ((temp.point == g && map[temp.point][i].first == h) || (temp.point == h && map[temp.point][i].first == g) || temp.chk == 1)
                    chk = 1;
                if ((visit[map[temp.point][i].first] == temp.n + map[temp.point][i].second && chk == 1) && chk_v[map[temp.point][i].first] != 1)
                    q.push({map[temp.point][i].first, temp.n + map[temp.point][i].second, chk});
                else if (visit[map[temp.point][i].first] == 0 || visit[map[temp.point][i].first] > temp.n + map[temp.point][i].second) {
                    if (goal[map[temp.point][i].first] == -1)
                        goal[map[temp.point][i].first] = 1;
                    visit[map[temp.point][i].first] = temp.n + map[temp.point][i].second;
                    if (chk == 0)
                        chk_v[map[temp.point][i].first] = 0;
                    else
                        chk_v[map[temp.point][i].first] = 1;
                    q.push({map[temp.point][i].first, temp.n + map[temp.point][i].second, chk});
                }
            }
        }
        for (int i = 0; i < 2001; i++) {
            if (goal[i] == -1)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}