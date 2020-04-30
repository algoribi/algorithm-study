// algorithm study
// BOJ_1138_한 줄로 서기

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, an[11] = {0};
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < n; j++) {
            if (an[j] == 0 && num == 0) {
                an[j] = i + 1;
                break;
            }
            if (an[j] == 0)
                num--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << an[i] << " ";
    }
    return 0;
}