#include <iostream>

using namespace std;

int main() {
    int n, d, k, c, arr[33005], sushi[3005] = {0}, counter = 0,ans = 0;
    cin >> n >> d >> k >> c;
    sushi[c]++;
    counter++;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i < k) {
            if (sushi[arr[i]] == 0)
                counter++;
            sushi[arr[i]]++;
        }
    }
    for (int i = 0; i < k; i++)
        arr[n + i] = arr[i];
    ans = counter;
    for (int i = k; i < n + k; i++) {
        if (sushi[arr[i]] == 0)
            counter++;
        sushi[arr[i]]++;
        sushi[arr[i - k]]--;
        if (sushi[arr[i - k]] == 0)
            counter--;
        if (counter > ans)
            ans = counter;
    }
    cout<<ans;
    return 0;
}