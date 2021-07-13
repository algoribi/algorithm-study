#include<algorithm>
#include<iostream>
#include<stack>
#define endl "\n"

using namespace std;

long long ans = 0, top, arr[100005];
stack<long long> s;

int main() {
    while(1) {
        int n, top;
        cin >> n;
        if (n == 0)
            break;
        s.push(0);
        arr[0] = 0;
        arr[n + 1] = 0;

        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        for (int i = 1; i <= n + 1; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                top = s.top();
                s.pop();
                ans = max(ans, arr[top]*(i - s.top() - 1));
            }
            s.push(i);
        }
        cout << ans << endl;
        while(!s.empty())
            s.pop();
        ans = 0;
    }
}