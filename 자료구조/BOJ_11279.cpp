#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;

priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.empty())
                cout << 0 << endl;
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else
            pq.push(x);
    }

    return 0;
}