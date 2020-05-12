// algorithm study
// BOJ_3053_택시 기하학

#include <iomanip>
#include <iostream>

using namespace std;

double pi = 3.14159265358979323846;

int main() {
    double r;
    cin >> r;
    cout << setprecision(6) << fixed << r * r * pi << '\n';
    cout << setprecision(6) << fixed << r * r * 2 << '\n';
    return 0;
}