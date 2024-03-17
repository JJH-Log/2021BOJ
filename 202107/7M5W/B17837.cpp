#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct info {
    int x, y;
    int axis, dir;
    int up, down; //0 : 위 또는 아래가 비어있음
};

vector<vector<int>> v;
vector<vector<int>> w; //현재 체스판 위에 누가 있는지 표현
vector<info> chip; //체스말들
int N, K;


pair<int, int> getPosInfo(int x, int y) { //top, cnt
    int now = w[x][y];
    int before = 0;
    int cnt = 0;
    while (now) {
        before = now;
        now = chip[before].up;
        cnt++;
    }
    return { before, cnt };
}

void reConnection(int X, int tar) {
    if (chip[X].down) chip[chip[X].down].up = tar;
    else w[chip[X].x][chip[X].y] = tar;
}

void setPos(int X, int dx, int dy) {
    chip[X].x = dx, chip[X].y = dy;
    if (chip[X].up) setPos(chip[X].up, dx, dy);
}

void move(int X, bool reversed) {
    int dx = chip[X].x + "10X21"[2 + chip[X].axis * chip[X].dir] - '1';
    int dy = chip[X].y + "01X12"[2 + chip[X].axis * chip[X].dir] - '1';
    int FLAG;
    if (dx >= 0 && dx < N && dy >= 0 && dy < N) FLAG = v[dx][dy];
    else FLAG = 2;
    if (FLAG <= 1) {
        reConnection(X, 0);
        pair<int, int> pos = getPosInfo(dx, dy);
        if (pos.second) chip[pos.first].up = X, chip[X].down = pos.first;
        else w[dx][dy] = X, chip[X].down = 0;
        setPos(X, dx, dy);
        if (FLAG == 1) {
            int before = -1;
            int now = X;
            while (now) {
                swap(chip[now].up, chip[now].down);
                before = now;
                now = chip[before].down;
            }
            chip[before].down = chip[X].up;
            reConnection(before, before);
            chip[X].up = 0;
        }
    }
    else {
        if (reversed) return;
        chip[X].dir *= -1;
        move(X, true);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    v.resize(N, vector<int>(N, 0));
    w.resize(N, vector<int>(N, 0));
    chip.resize(K + 1);
    int i, j, x, y, d, T;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) cin >> v[i][j];
    }
    for (i = 1; i <= K; i++) {
        cin >> x >> y >> d;
        x--, y--;
        w[x][y] = i;
        chip[i] = { x, y, 1, -1, 0, 0 };
        if (d < 3) chip[i].axis = 2;
        if (d == 1 || d == 4) chip[i].dir = 1;
    }
    for (T = 1; T <= 1000; T++) {
        for (i = 1; i <= K; i++) {
            move(i, false);
            if (getPosInfo(chip[i].x, chip[i].y).second >= 4) {
                cout << T;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}