#include <iostream>

using namespace std;

int main() {
    int t, n, d;
    cin>>t;

    for (int i = 0; i < t; i++) {
        cin>>n>>d;
        int count0 = 0, answer = 0, temp;
        for (int j = 0; j < n; j++) {
            cin>>temp;
            if (temp == 0) count0++;
            else {
                answer += count0/d;
                count0 = 0;
            }
        }
        answer += count0/d;
        cout<<"#"<<i+1<<" "<<answer<<"\n";
    }
    return 0;
}