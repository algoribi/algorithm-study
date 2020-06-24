// algorithm study
// BOJ_2890_카약

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c, num[10];
    cin >> r >> c;
    vector<int> arr[55];
    for (int i = 0; i < r; i++) {
        int counter = 0, save = -1;
        for (int j = 0; j < c; j++) {
            char c;
            cin >> c;
            if (c >= '0' && c <= '9')
                save = c - '0';
            if (save != -1 && c == '.')
                counter++;
        }
        if (save != -1)
            arr[counter].push_back(save);
    }
    int number = 1;
    for (int i = 0; i < 55; i++) {
        if (arr[i].size() == 0)
            continue;
        for (int j = 0; j < arr[i].size(); j++) {
            num[arr[i][j]] = number;
        }
        number++;
    }
    for (int i = 1; i < 10; i++) {
        cout << num[i] << "\n";
    }
    return 0;
}