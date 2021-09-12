#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define endl "\n"
#define ll long long

using namespace std;

int solution(int n, int k) {
    int answer = 0;

    int num = n;
    string re_num;
    while (1) {
        if (num <= 0)
            break;
        re_num += to_string(num % k);
        num /= k;
    }
    reverse(re_num.begin(), re_num.end());

    istringstream ss(re_num);
    string stringBuffer;
    vector<string> subString;
    while (getline(ss, stringBuffer, '0'))
        subString.push_back(stringBuffer);

    for (int i = 0; i < subString.size(); i++) {
        if (subString[i] == "")
            continue;
        ll longNum = stol(subString[i]);

        if (longNum == 1L)
            continue;

        bool chk = true;
        for (ll i = 2; i * i <= longNum; i++) {
            ll num = longNum % i;
            if (num == 0)
                chk = false;
        }
        if (chk == true)
            answer++;
    }
    return answer;
}

int main() {
    int n = 437674;
    int k = 3;
    cout << solution(n, k);
}