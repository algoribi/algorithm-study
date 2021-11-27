#include <iostream>
#include <deque>

using namespace std;

int main() {
    int test_case, n;
    deque<char> d;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        char c;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> c;
            if (i == 0 || d.front() < c)
                d.push_back(c);
            else 
                d.push_front(c);
        }
        for(int i = 0; i < d.size(); i++)
            cout<<d[i];
        cout << "\n";
        d.clear();
    }
    return 0;
}