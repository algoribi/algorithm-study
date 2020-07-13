#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string t, p;
    getline(cin, t);
    getline(cin, p);
    vector<int> fail(p.size(), 0), answer;
    for (int i = 1, j = 0; i < p.size(); i++) {
        while(j > 0 && p[i] != p[j])
            j = fail[j - 1];
        if (p[i] == p[j])
            fail[i] = ++j;
    }

    for (int i = 0, j = 0; i < t.size(); i++) {
        while(j > 0 && t[i] != p[j])
            j = fail[j - 1];
        if (t[i] == p[j]) {
            if (j == p.size() - 1) {
                answer.push_back(i + 1 - j);
                j = fail[j];
            }
            else j++;
        }
    }
    cout<<answer.size()<<"\n";
    for (int i = 0; i < answer.size(); i++) {
        cout<<answer[i]<<" ";
    }
    return 0;
}