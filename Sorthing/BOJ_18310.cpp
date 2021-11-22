#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
   
    if (n % 2 == 0)
        cout << v[n/2 - 1];
    else
        cout << v[n/2];
    
    return 0;
}