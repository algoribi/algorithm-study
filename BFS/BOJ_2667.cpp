// BOJ_2667_단지번호 붙이기

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, board[505][505], visit[5005], comp_size = 0;
vector<int> graph[5000], ans;

int convert(int row, int col) {
    return n * row + col;
}

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int here) {
    comp_size++;
    visit[here] = 1;
    for (int i = 0; i < graph[here].size(); i++) {
        int there = graph[here][i];
        if (visit[there] == 0)
            dfs(there);
    }
}
void dfsAll() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (visit[convert(i, j)] == 0 && board[i][j] == 1) {
                dfs(convert(i, j));
                ans.push_back(comp_size);
                comp_size = 0;
            }
        }
}

int direct_R[4] = {0, 0, 1, -1};
int direct_C[4] = {1, -1, 0, 0};

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 1)
                continue;
            int curRow = i, curCol = j;
            for (int k = 0; k < 4; k++) {
                int nextRow = curRow + direct_R[k];
                int nextCol = curCol + direct_C[k];
                if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && board[nextRow][nextCol] == 1)
                    addEdge(convert(curRow, curCol), convert(nextRow, nextCol));
            }
        }
    }
    dfsAll();
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}