#include <algorithm>
#include <iostream>
#include <vector>

#define endl "\n"
using namespace std;

int main() {
    int test;
    string grades[] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
    cin >> test;
    for (int t = 1; t <= test; t++) {
        int n, k, mid, fin, repo, counter = 0;
        double d[110];
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> mid >> fin >> repo;
            d[i] = mid * 0.35 + fin * 0.45 + repo * 0.2;
        }
        for (int i = 1; i <= n; i++) {
            if (d[k] < d[i])
                counter++;
        }
        cout << "#" << t << " " << grades[counter/(n/10)] << endl;
    }
    return 0;
}