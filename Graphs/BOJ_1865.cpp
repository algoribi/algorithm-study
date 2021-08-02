#include <iostream>
#include <vector>

#define endl "\n"
#define MAX 30000000

using namespace std;

struct eg {
    int s, e, t;
};

int n, m, w;
bool chk(vector<eg> v) {
    vector<int> dist(n + 1, MAX);

    int s, e, t;
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < v.size(); j++) {
            s = v[j].s;
            e = v[j].e;
            t = v[j].t;
            if (dist[e] > dist[s] + t)
                dist[e] = dist[s] + t;
        }
    }
    for (int j = 0; j < v.size(); j++) {
        s = v[j].s;
        e = v[j].e;
        t = v[j].t;
        if (dist[e] > dist[s] + t)
            return true;
    }

    return false;
}

int main() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n >> m >> w;
        int s, e, t;
        vector<eg> v;
        for (int j = 0; j < m; j++) {
            cin >> s >> e >> t;
            v.push_back({s, e, t});
            v.push_back({e, s, t});
        }
        for (int j = 0; j < w; j++) {
            cin >> s >> e >> t;
            v.push_back({s, e, -t});
        }
        if (chk(v))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}