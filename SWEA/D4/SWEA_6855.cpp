#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, arr[100010], answer = 0;
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        vector<int> v;
        for (int j = 1; j < n; j++) {
            v.push_back(arr[j] - arr[j - 1]);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int j = k - 1; j < v.size(); j++) {
            answer += v[j];
        }
        cout<<"#"<<i + 1<<" "<<answer<<"\n";
    }
    return 0;
}