#include <vector>

using namespace std;

int number_of_area, max_size_of_one_area, sum;
int visit[110][110];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int m, int n, vector<vector<int>> picture) {
    visit[x][y] = 1;
    sum++;
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= m || newy < 0 || newy >= n || picture[newx][newy] != picture[x][y] || visit[newx][newy] == 1)
            continue;
        dfs(newx, newy, m, n, picture);
    }
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    number_of_area = 0;
    max_size_of_one_area = 0;
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 110; j++) {
            visit[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j] == 0 && picture[i][j] != 0) {
                sum = 0;
                dfs(i, j, m, n, picture);
                number_of_area++;
                if (sum > max_size_of_one_area)
                    max_size_of_one_area = sum;
            }
        }
    }
    vector<int> answer;
    answer.push_back(number_of_area);
    answer.push_back(max_size_of_one_area);
    return answer;
}