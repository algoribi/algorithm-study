#include<bits/stdc++.h>
using namespace std;
#define v vector
#define vi v<int>
#define vvi v<vi>
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n;
bool isrange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < n;
}
void print(vvi& board) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int solution(vector<vector<int>> grid) {
	int answer = 0;
	n = grid.size();
	while (true) {
		vvi temp = grid;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!grid[i][j])continue;
				bool flag = true;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (isrange(ny, nx) && grid[ny][nx]==0)
						flag = false;
				}
				if (flag) {
					int Min = 1e7;
					for (int k = 0; k < 4; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (isrange(ny, nx)) {
							Min = min(Min, grid[ny][nx]);
						}
					}
					temp[i][j] = Min+1;
				}
			}
		}
		if (grid == temp)break;
		grid = temp;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, grid[i][j]);
		}
	}

	return answer;
}