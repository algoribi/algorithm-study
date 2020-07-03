#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num[5];
    cin>>num[0]>>num[1]>>num[2];
    sort(num, num + 3);
    cout<<num[1];
    return 0;
}