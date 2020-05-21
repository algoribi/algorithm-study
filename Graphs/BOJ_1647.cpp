// BOJ_1647_도시 분할 계획

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, parent[100001];
vector<tuple<int, int, int> > v;

int Find(int num) {
    if (num == parent[num])
        return num;
    else
        return parent[num] = Find(parent[num]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        parent[y] = x;
        n--;
        return true;
    } else
        return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_tuple(c, a, b));
    }
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    sort(v.begin(), v.end());

    int an = 0;
    for (int i = 0; i < v.size(); i++) {
        int x = get<1>(v[i]);
        int y = get<2>(v[i]);
        if (n == 2)
            break;
        if (Union(x, y))
            an += get<0>(v[i]);
    }
    cout << an << '\n';
    return 0;
}