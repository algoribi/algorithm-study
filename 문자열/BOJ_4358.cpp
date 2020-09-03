#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s;
    map<string, double> m;
    double counter = 0;
    while (getline(cin, s)) {
        counter++;
        if (m.find(s) == m.end())
            m.insert(make_pair(s, 1));
        else
            m[s]++;
    }
    cout.setf(ios::fixed);
    cout.precision(4);
    for (auto it = m.begin(); it != m.end(); it++) {
        double num = it->second / counter * 100;
        cout << it->first << " " << num << "\n";
    }
}