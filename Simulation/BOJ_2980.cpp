// algorithm study
// BOJ_2980_도로와 신호등

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct t {
    int d;
    int r;
    int g;
};

bool t_sort(t a, t b) {
    return a.d < b.d;
}

int time(int r, int g, int now) {
    if (r + g > now) {
        if (r < now)
            return 0;
        else
            return r - now;
    } else if (now % (r + g) > r)
        return 0;
    else
        return r - (now % (r + g));
}

int main() {
    int n, l, answer = 0;
    cin >> n >> l;
    vector<t> go;

    for (int i = 0; i < n; i++) {
        t temp;
        cin >> temp.d >> temp.r >> temp.g;
        go.push_back(temp);
    }
    sort(go.begin(), go.end(), t_sort);

    for (int i = 0; i < n; i++) {
        if (i == 0)
            answer += go[i].d;
        else
            answer += go[i].d - go[i - 1].d;
        answer += time(go[i].r, go[i].g, answer);
    }
    answer += l - go[n - 1].d;
    cout << answer;

    return 0;
}