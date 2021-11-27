#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> grid) {
    int answer = 0, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != 0)
                q.push({i, j});
        }
    }

    while (!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();

        if (grid[f.first][f.second] > answer)
            answer = grid[f.first][f.second];

        int counter = 0, chk_min = 500000;
        for (int i = 0; i < 4; i++) {
            int newx = f.first + dx[i];
            int newy = f.second + dy[i];
            if (newx >= grid.size() || newx < 0 || newy >= grid[0].size() || newy < 0)
                continue;
            if (grid[newx][newy] == 0)
                counter++;
            if (grid[newx][newy] != 0 && grid[newx][newy] < chk_min)
                chk_min = grid[newx][newy];
        }

        if (counter == 0 && grid[f.first][f.second] < chk_min + 1) {
            grid[f.first][f.second] = chk_min + 1;
            q.push({f.first, f.second});
        }
    }

    return answer;
}

// input
int main() {
    vector<vector<int>> grid = {{0}};
    cout << solution(grid) << "\n";
    return 0;
}