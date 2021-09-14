#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

bool chk[1000010] = {0};
vector<int> answer;

void rec(vector<int> v, int n) {
    if (v.size() == 1) {
        answer.push_back(v[0]);
        return;
    }
    for (int i = 2; i < n; i++) {
        if(chk[i] == false || v.size() % i != 0)
            continue;
        vector<int> t;
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < v.size() / i; k++)
                t.push_back(v[j + (k * i)]);
            rec(t, n);
            t.clear();
        }
        return;
    }
}

vector<int> solution(int n) {
    vector<int> v;
    v.push_back(1);
    // 에라토스테네스의 체
    for (int i = 2; i <= n; i++) {
        v.push_back(i);
        if (chk[i] != 0)
            continue;
        int num = 1;
        while (1) {
            if (i * num > n)
                break;
            chk[i * num++] = true;
        }
    }
    rec(v, n);
    return answer;
}

int main() {
    vector<int> a = solution(12);
    for (int i = 0; i < a.size(); i++)
        cout<< a[i]<<" ";
    return 0;
}