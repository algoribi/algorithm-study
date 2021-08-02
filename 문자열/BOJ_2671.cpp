#include <iostream>
#include <regex>

using namespace std;

int main() {
    string str;
    cin >> str;
    if (regex_match(str, regex("(100+1+|01)+")))
        cout << "SUBMARINE";
    else
        cout << "NOISE";

    return 0;
}