// algorithm study
// BOJ_1966_프린터 큐

#include <iostream>
#include <queue>

using namespace std;

struct q {
    int a;  //순서
    int b;  //중요도
};

int main() {
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        queue<q> que;
        priority_queue<int> pq;
        for (int j = 0; j < n; j++) {
            q temp;
            temp.a = j;
            cin >> temp.b;
            que.push(temp);
            pq.push(temp.b);
        }
        int count = 0;
        while (1) {
            int ind = que.front().a;
            int num = que.front().b;
            que.pop();
            if (pq.top() == num) {
                pq.pop();
                count++;
                if (ind == m) {
                    cout << count << '\n';
                    break;
                }
            }
            q temp;
            temp.a = ind;
            temp.b = num;
            que.push(temp);
        }
    }
    return 0;
}