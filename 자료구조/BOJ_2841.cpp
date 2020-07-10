#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p, a, b, answer = 0;
    cin >> n >> p;
    vector<int> s[10];
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (s[a].size() == 0) {
            s[a].push_back(b);
            answer++;
        } else {
            if (s[a].back() == b)
                continue;
            else if (s[a].back() < b) {
                s[a].push_back(b);
                answer++;
            } else {
                while (1) {
                    if (s[a].size() == 0 || s[a].back() < b) {
                        s[a].push_back(b);
                        answer++;
                        break;
                    } else if (s[a].back() == b)
                        break;
                    s[a].pop_back();
                    answer++;
                }
            }
        }
    }
    cout << answer;
}