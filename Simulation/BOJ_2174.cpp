#include <iostream>
#include <map>

using namespace std;

struct robot {
    int x, y, d;
};

int A, B, N, M, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, land[105][105];
map<int, robot> m;

int go(int rb, int num) {
    int going = m[rb].d, rx = m[rb].x, ry = m[rb].y;
    for (int i = 0; i < num; i++) {
        land[rx][ry] = 0;
        rx += dx[going];
        ry += dy[going];
        if (rx <= 0 || ry <= 0 || rx > B || ry > A)
            return -1;
        else if (land[rx][ry] != 0)
            return land[rx][ry];
    }
    m[rb].x = rx;
    m[rb].y = ry;
    land[rx][ry] = rb;
    return 0;
}

int turn(int rb, int num, char dd) {
    num = num % 4;
    if (dd == 'R')
        m[rb].d = (m[rb].d + num) % 4;
    else {
        m[rb].d -= num;
        if (m[rb].d < 0)
            m[rb].d += 4;
    } 
    return 0;
}

int main() {
    int x, y, t;
    char c;
    cin >> A >> B >> N >> M;
    for (int i = 1; i <= N; i++) {
       cin >> y >> x >> c;
       land[B + 1 - x][y] = i;
       if (c == 'N')
           t = 0;
       else if (c == 'E')
           t = 1;
       else if (c == 'S')
           t = 2;
       else
           t = 3;
       m[i] = {B + 1 - x, y, t};
    }
    for (int i = 0; i < M; i++) {
        cin >> x >> c >> y;
        if (c == 'F')
            t = go(x, y);
        else
            t = turn(x, y, c);
        if (t == -1){
            cout << "Robot "<< x <<" crashes into the wall";
            return 0;
        } else if (t > 0) {
            cout << "Robot "<< x <<" crashes into robot " << t;
            return 0;
        }
    }

    cout << "OK";
    return 0;
}