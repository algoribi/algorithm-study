from collections import deque

n, m = map(int, input().split())
miro = []
for i in range(n):
    s = input()
    miro.append(s)

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
visit = [[0 for col in range(110)] for row in range(110)]
dq = deque()
dq.append((0, 0))
visit[0][0] = 1

while True:
    if len(dq) == 0:
        break

    x, y = dq.popleft()
    for i in range(4):
        newx = dx[i] + x
        newy = dy[i] + y
        if newx >= n or newx < 0 or newy >= m or newy < 0:
            continue
        if miro[newx][newy] == "1":
            if visit[newx][newy] == 0:
                visit[newx][newy] = visit[x][y] + 1
                dq.append((newx, newy))
            elif visit[newx][newy] != 0 and visit[newx][newy] > visit[x][y] + 1:
                visit[newx][newy] = visit[x][y] + 1
                dq.append((newx, newy))

print(visit[n - 1][m - 1])
