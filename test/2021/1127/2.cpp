#include<bits/stdc++.h>
using namespace std;
#define v vector
#define vi v<int>
#define vvi v<vi>
int dy[8] = { 0,1,0,-1,0,-1,0,1 };
int dx[8] = { -1,0,1,0,-1,0,1,0 };
int n, m;
bool isrange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}

vector<vector<int>> solution(int r, int c) {
	vector<vector<int>> board = vvi(r, vi(c));
	n = r;
	m = c;
	int cnt = 0;
	int y = 0, x = c - 1;
	int dir = 0;
	while (cnt < r * c) {
		while (board[y][x] == 0 && cnt < r * c&& !(dir == 3 || dir == 7)) {
			board[y][x] = ++cnt;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (!isrange(ny, nx))
				break;
			if (board[ny][nx])
				break;
			y = ny;
			x = nx;
		
		}
		dir = (dir + 1) % 8;
		y += dy[dir];
		x += dx[dir];
		if (dir == 3 || dir == 7)
			board[y][x] = ++cnt;
	}
	return board;
}