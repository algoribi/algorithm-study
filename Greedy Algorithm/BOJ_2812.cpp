#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
vector<char> start;
queue<char> back;
long long answer = 0;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        back.push(temp);
    }
    start.push_back(back.front());
    back.pop();
    while (k != 0) {
        if (back.empty())
            break;
        if (start.back() < back.front()) {
            start.pop_back();
            k--;
        }
        if (start.size() == 0 || start.back() >= back.front()) {
            start.push_back(back.front());
            back.pop();
        }
    }
    for (int i = k; i > 0; i--) {
        start.pop_back();
    }
    string ans = "";
    for (int i = 0; i < start.size(); i++) {
        ans.push_back(start[i]);
    }
    while (!back.empty()) {
        ans.push_back(back.front());
        back.pop();
    }
    cout << ans;
}