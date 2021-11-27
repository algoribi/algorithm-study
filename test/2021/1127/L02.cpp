#include <iostream>
#include <string>
#include <vector>

using namespace std;

int map[1001][1001], go_r, go_c, go_d, counter = 1;
int dx[] = {0, 1, 0, -1, 0, -1, 0, 1}, dy[] = {-1, 0, 1, 0, -1, 0, 1, 0};

void move(int maxgo, int moveD) {
    int newc, newr;
    while (1) {
        if (dx[moveD] == 0 && go_c != maxgo) {
            newr = go_r;
            if (maxgo == 0)
                newc = go_c - 1;
            else 
                newc = go_c + 1;
        } else if (dy[moveD] == 0 && go_r != maxgo) {
            newc = go_c;
            if (maxgo == 0)
                newr = go_r - 1;
            else
                newr = go_r + 1;
        } else 
            break;

        if (map[newr][newc] == 0) {
            map[newr][newc] = counter;
            go_r = newr;
            go_c = newc;
            counter++;
        } else 
            break;
    }
}

vector<vector<int>> solution(int r, int c) {
    vector<vector<int>> answer;
    go_r = 0; go_c = c; go_d = 0;
    while (counter <= r * c) {
        int direction = go_d % 8;
        go_d++;
        if (direction == 3) {
            go_r--;
            map[go_r][go_c] = counter;
            counter++;
            continue;
        } else if (direction == 7) {
            go_r++;
            map[go_r][go_c] = counter;
            counter++;
            continue;
        } else if (direction == 0 || direction == 4 || direction == 5)
            move(0, direction);
        else if (direction == 1)
            move(r - 1, direction);
        else 
            move(c - 1, direction);
    }

    for (int i  = 0; i < r; i++) {
        vector<int> t;
        for (int j = 0; j < c; j++)
            t.push_back(map[i][j]);
        answer.push_back(t);
        t.clear();
    }

    return answer;
}

// input
int main() {
    int r = 3, c = 5;
    vector<vector<int>> ans = solution(r, c);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) 
            cout << ans[i][j] << ", ";
        cout << "\n";
    }

    return 0;
}