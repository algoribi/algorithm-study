#include <cmath>
#include <iostream>

using namespace std;

bool chk[10000010] = {false};

int main() {
    long long a, b, answer = 0;
    cin >> a >> b;
    for (int i = 2; i <= sqrt(b); i++) {
        if (chk[i] != false)
            continue;
        int num = 2;
        while (1) {
            if (i * num > sqrt(b))
                break;
            chk[i * num++] = true;
        }
    }
    for (int i = 2; i <= sqrt(b); i++) {
        if (chk[i] != false)
            continue;
        long long num = i, sum = i;
        while (1) {
            if (sum * num % sum != 0)
                break;
            sum *= num;
            if (sum >= a && sum <= b)
                answer++;
            else if (sum > b)
                break;
        }
    }
    cout << answer;
    return 0;
}