#include <iostream>
#include <vector>

using namespace std;

int chk[1000001] = {0}, num[1000001] = {0}, fl = 0;

void dfs(int n) {
    num[n] = 2;
    int arr[10], counter = 0, new_num = 0, number = n;
    for (int i = 1000000; i >= 1; i /= 10) {
        if (number < i && counter == 0)
            continue;
        if (i == 1)
            arr[counter] = number;
        else {
            arr[counter] = number / i;
            number %= i;
            counter++;
        }
    }
    for (int i = 0; i <= counter; i++) {
        new_num += arr[i] * arr[i];
    }
    if (new_num == 1) {
        fl = 1;
        num[n] = 1;
    } else if (num[new_num] == 1) {
        fl = 1;
        num[n] = 1;
    } else if (num[new_num] == 2)
        return;
    else {
        dfs(new_num);
        if (fl == 1)
            num[n] = 1;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (chk[i] == 0) {
            for (int j = i + i; j <= n; j += i) {
                chk[j] = 1;
            }
        }
    }
    vector<int> answer;
    for (int i = 2; i <= n; i++) {
        if (chk[i] == 1)
            continue;
        if (num[i] == 0)
            dfs(i);
        if (num[i] == 1)
            answer.push_back(i);
        fl = 0;
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}