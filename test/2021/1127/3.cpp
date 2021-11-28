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
int change(int dir, int num) {
	if (num == 1) {
		if (dir == 0)
			return 1;
		if (dir == 3)
			return 2;
		return (dir + 2) % 4;
	}
	else if (num == 2) {
		if (dir == 0)
			return 3;
		if (dir == 1)
			return 2;
		return (dir + 2) % 4;
	}
	else if (num == 3) {
		if (dir == 2)
			return 1;
		if (dir == 3)
			return 0;
	}
	else if (num == 4) {
		if (dir == 2) 
			return 3;
		if (dir == 1)
			return 0;
	}
	return (dir + 2) % 4;
}

int solution(vector<vector<int>> board, vector<vector<int>> durability) {
	int answer = 0;
	n = board.size();
	int y = 0, x = 0;
	int dir = 1;
	if (durability[0][0])
		return 0;
	answer = 0;
	while (isrange(y,x)) {
		if (durability[y][x]>0) {
			durability[y][x]--;
			answer++;
			dir = change(dir, board[y][x]);
			y += dy[dir];
			x += dx[dir];
			
			continue;
		}
		y += dy[dir];
		x += dx[dir];
		answer++;
	}
	answer--;
	return answer;
}