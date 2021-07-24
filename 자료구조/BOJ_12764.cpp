#include <iostream>
#include <queue>
#include <set>

#define endl "\n"

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pe, out;
set<int> seat;
int seatCount[100010] = {0};

int main() {
    int n, p, q, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> q;
        pe.push(make_pair(p, q));
    }
    for (int i = 0; i < n; i++) {
        pair<int, int> top = pe.top();
        pe.pop();
        while (!out.empty() && out.top().first <= top.first) {
            seat.insert(out.top().second);
            out.pop();
        }
        if (seat.empty()) {
            seatCount[ans]++;
            out.push(make_pair(top.second, ans));
            ans++;
        } else {
            seatCount[*seat.begin()]++;
            out.push(make_pair(top.second, *seat.begin()));
            seat.erase(seat.begin());
        }
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
        cout << seatCount[i] << " ";

    return 0;
}