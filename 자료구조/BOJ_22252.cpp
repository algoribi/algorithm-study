#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define endl "\n"

using namespace std;

map<string, priority_queue<int, vector<int>, less<int>>> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long q, ans = 0, tn, n, t;
    priority_queue<int, vector<int>, less<int>> temp;
	cin >> q;
	for (long long i = 0; i < q; i++) {
        cin >> tn;
        if (tn == 1) {
            string s;
            cin >> s;
            if (m.find(s) == m.end())
                m.insert({s, temp});
            cin >> n;
            for (long long j = 0; j < n; j++) {
                cin >> t;
                m[s].push(t);
            }
        } else {
            string s;
            cin >> s >> n;
            long long c;
            if (m.find(s) == m.end())
                continue;
            else if (n > m[s].size())
                c = m[s].size();
            else 
                c = n;
            for (long long j = 0; j < c; j++) {
                ans += m[s].top();
                m[s].pop();
            }
        }
    }
    cout << ans;
}