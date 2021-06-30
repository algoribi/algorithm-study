#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K, w, v, memo[105][100005] = {0};
vector<pair<int, int>> bag;

int rec(int weight, int counter) {
    if (memo[counter][weight] != 0)
        return memo[counter][weight];
    if (counter == N)
        return 0;
    pair<int, int> p = bag[counter];
    if (weight + p.first <= K)
        return memo[counter][weight] = max(p.second + rec(weight + p.first, counter + 1), rec(weight, counter + 1));
    else
        return memo[counter][weight] = max(0, rec(weight, counter + 1));
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> w >> v;
        bag.push_back({w, v});
    }
    cout << rec(0, 0);
    return 0;
}