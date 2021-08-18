#include <iostream>
#define endl "\n"

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    for (int t = 1; t <= test_case; t++) {
        int money[] = {50000, 10000, 5000, 1000, 500, 100, 50, 10}, ans[8] = {0};
        int n;
        cin >> n;
        for (int i = 0; i < 8; i++) {
            int a = n / money[i];
            n = n % money[i];
            ans[i] = a;
        }
        cout << "#" << t << endl;
        for (int i = 0; i < 8; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}