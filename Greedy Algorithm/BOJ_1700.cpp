// algorithm_study
// BOJ_1700_멀티탭 스케줄링

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k, arr[110], answer = 0;
    set<int> s;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++) {
        if (s.find(arr[i]) != s.end())
            continue;
        else if (s.size() == n && n == 1) {
            s.clear();
            answer++;
        } else if (s.size() == n) {
            int count = 0, find[110] = {0};
            for (int j = i + 1; j < k; j++) {
                if (s.find(arr[j]) != s.end() && find[arr[j]] == 0) {
                    count++;
                    find[arr[j]] = 1;
                }
                if (count == n - 1)
                    break;
            }
            for (auto it = s.begin(); it != s.end(); it++) {
                if (find[*it] == 0) {
                    s.erase(*it);
                    break;
                }
            }
            answer++;
        }
        s.insert(arr[i]);
    }
    cout << answer;
    return 0;
}