#include <iostream>

using namespace std;

int dp[10010] = {0};

int main() {
    int N, ans = 0;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int time, num, maxtime = 0, temp;
        cin>>time>>num;
        for (int j = 0; j < num; j++) {
            cin>>temp;
            if (dp[temp] > maxtime)
                maxtime = dp[temp];
        }
        dp[i] = maxtime + time;
        if (dp[i] > ans)
            ans = dp[i];
    }
    cout<<ans;
    return 0;
}