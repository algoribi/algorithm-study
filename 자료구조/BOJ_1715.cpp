// algorithm_study
// BOJ_1715_카드 정렬하기

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, temp, answer = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        pq.push(temp);
    }
    while (pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        answer += a + b;
        pq.push(a + b);
    }
    cout << answer;
    return 0;
}