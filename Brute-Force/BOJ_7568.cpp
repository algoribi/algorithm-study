#include <iostream>

using namespace std;

int main() {
    int n, answer[55] = {0}; cin>>n;
    pair<int, int> p[55];
    for (int i = 0; i < n; i++) {
        cin>>p[i].first>>p[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].first > p[j].first && p[i].second > p[j].second) answer[j]++;
            else if (p[i].first < p[j].first && p[i].second < p[j].second) answer[i]++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<answer[i] + 1<<" ";
    }
    return 0;
}