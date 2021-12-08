#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int h, w, x, y, t, num[305][305];
    cin >> h >> w >> x >> y;

    for (int i = 0; i < h + x; i++) {
        for (int j = 0; j < w + y; j++) {
            cin >> t;
            if (i < h && j < w)
                num[i][j] = t;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i >= x && j >= y)
                num[i][j] -= num[i - x][j - y];
            cout << num[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}