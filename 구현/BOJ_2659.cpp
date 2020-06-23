#include <iostream>

using namespace std;

int main() {
    int num[4], answer = 0;
    cin >> num[0] >> num[1] >> num[2] >> num[3];
    int min_num = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
    for (int i = 1; i <= 3; i++) {
        int temp = num[(0 + i) % 4] * 1000 + num[(1 + i) % 4] * 100 + num[(2 + i) % 4] * 10 + num[(3 + i) % 4];
        if (temp < min_num)
            min_num = temp;
    }
    for (int i = 1111; i < min_num; i++) {
        int arr[4], counter = 0, chk = 0;
        arr[0] = i / 1000;
        arr[1] = i / 100 - arr[0] * 10;
        arr[2] = i / 10 - arr[1] * 10 - arr[0] * 100; 
        arr[3] = i - arr[0] * 1000 - arr[1] * 100 - arr[2] * 10;
        for (int j = 1; j <= 3; j++) {
            int temp = arr[(0 + j) % 4] * 1000 + arr[(1 + j) % 4] * 100 + arr[(2 + j) % 4] * 10 + arr[(3 + j) % 4];
            if (temp < i) {
                chk = 1;
                break;
            }
        }
        if (chk == 0)
            answer++;
    }
    cout << answer + 1;
}