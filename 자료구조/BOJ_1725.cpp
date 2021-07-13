#include<algorithm>
#include<iostream>
#include<stack>

using namespace std;

int n, ans = 0, top, arr[100005];
stack<int> s;

int main() {
	cin >> n;
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
	cout << ans;
}