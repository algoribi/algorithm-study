// algorithm study
// BOJ_8980_택배

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct box {
    int a;
    int b;
    int num;
};

bool sort_box(box b1, box b2) {
    if (b1.b == b2.b)
        return b1.a < b2.a;
    return b1.b < b2.b;
}

int main() {
    int n, c, m, town[2010] = {0}, counter = 0;
    cin >> n >> c >> m;
    vector<box> v;
    for (int i = 0; i < m; i++) {
        box temp;
        cin >> temp.a >> temp.b >> temp.num;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), sort_box);
    for (int i = 0; i < v.size(); i++) {
        int max_town = 0, temp;
        for (int j = v[i].a; j < v[i].b; j++) {
            if (town[j] > max_town)
                max_town = town[j];
        }
        if (max_town == c)
            continue;
        else if (c - max_town >= v[i].num)
            temp = v[i].num;
        else
            temp = c - max_town;
        for (int j = v[i].a; j < v[i].b; j++) {
            town[j] += temp;
        }
        counter += temp;
    }
    cout << counter;
    return 0;
}