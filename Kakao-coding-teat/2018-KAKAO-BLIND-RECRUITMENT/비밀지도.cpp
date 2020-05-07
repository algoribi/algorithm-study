#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    int map1[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            map1[i][j] = arr1[i] % 2;
            arr1[i] /= 2;
        }
    }

    int map2[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            map2[i][j] = arr2[i] % 2;
            arr2[i] /= 2;
        }
    }

    vector<string> answer;
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if (map1[i][j] == 1 || map2[i][j] == 1) {
                s = s + "#";
            } else if (map1[i][j] == 0 && map2[i][j] == 0) {
                s = s + " ";
            }
        }
        answer.push_back(s);
    }
    return answer;
}