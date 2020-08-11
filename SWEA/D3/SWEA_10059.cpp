#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    for (int t = 0; t < testcase; t++) {
        cout << "#" << t + 1 << " ";
        string s;
        cin >> s;
        int num = (s[0] - '0') * 10 + (s[1] - '0'), chk1 = 0;
        int num2 = (s[2] - '0') * 10 + (s[3] - '0'), chk2 = 0;
        if (num > 12 || num == 0)
            chk1 = 1;
        if (num2 > 12 || num2 == 0)
            chk2 = 1;

        if (chk1 == 0 && chk2 == 1)
            cout << "MMYY" << endl;
        else if (chk1 == 1 && chk2 == 0)
            cout << "YYMM" << endl;
        else if (chk1 == 0 && chk2 == 0)
            cout << "AMBIGUOUS" << endl;
        else
            cout << "NA" << endl;
    }
    return 0;
}