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

vector<vector<int>> v;
vector<int> w;
vector<pair<int, int>> spell;
int marble[5] = { 0, }; //0과 4는 dummy
int N, M;

void flatten() {
    int x, y, d, nx, ny; //왼아오위
    int dcnt, dlen;
    x = y = N / 2;
    dcnt = d = 0;
    dlen = 1;
    while (true) {
        nx = x + "1210"[d] - '1';
        ny = y + "0121"[d] - '1';
        if (ny < 0) break;
        w.push_back(v[nx][ny]);
        dcnt++;
        if (dcnt == dlen) {
            dcnt = 0;
            d = (d + 1) % 4;
            if (d == 0 || d == 2) dlen++;
        }
        x = nx, y = ny;
    }
    return;
}

void init_spell() {
    spell.push_back({ 6, 15 });
    spell.push_back({ 2, 11 });
    spell.push_back({ 0, 9 });
    spell.push_back({ 4, 13 });
}

void blizzard(int d, int s) {
    int now, len, cnt;
    now = spell[d - 1].first;
    len = spell[d - 1].second;
    cnt = 0;
    while (cnt < s) {
        w[now] = 4;
        now += len;
        len += 8;
        cnt++;
    }
    return;
}

bool boom(bool isBegin) {
    int i, before;
    int cnt;
    bool result = false;
    cnt = before = 0;
    for (i = 0; (i < N * N - 1) && w[i]; i++) {
        if (w[i] == 4) continue;
        else {
            if (before == w[i]) cnt++;
            else if (cnt > 3) {
                result = true;
                if(isBegin) cnt++; //무조건 사이에 4가 있기 때문
                while (cnt) {
                    marble[w[i - cnt]]++;
                    w[i - cnt] = 4, cnt--;
                }
            }
            else cnt = 1;
            before = w[i];
        }
    }
    if (cnt > 3) {
        result = true;
        if (isBegin) cnt++; //무조건 사이에 4가 있기 때문
        while (cnt) {
            marble[w[i - cnt]]++;
            w[i - cnt] = 4, cnt--;
        }
    }
    return result;
}

void compress() {
    int i, j;
    j = 0;
    for (i = 0; (i < N * N - 1) && w[i]; i++) {
        if (w[i] == 4) j++;
        else w[i - j] = w[i];
    }
    for (; j > 0; j--) w[i - j] = 0;
    return;
}

void alchemize() {
    vector<int> temp;
    int i, before;
    int cnt;
    bool result = false;
    cnt = before = 0;
    for (i = 0; (i < N * N - 1) && w[i]; i++) {
        if (before == w[i]) cnt++;
        else {
            if (before) {
                temp.push_back(cnt);
                temp.push_back(before);
            }
            cnt = 1;
            before = w[i];
        }
    }
    if (before) {
        temp.push_back(cnt);
        temp.push_back(before);
    }
    for (i = 0; i < min(N * N - 1, (int)temp.size()); i++) w[i] = temp[i];
    for (; i < N * N - 1; i++) w[i] = 0;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, d, s;
    cin >> N >> M;
    v.resize(N, vector<int>(N, 0));
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) cin >> v[i][j];
    }
    flatten();
    init_spell();

    for (i = 0; i < M; i++) {
        cin >> d >> s;
        blizzard(d, s);
        boom(true);
        compress();
        while (boom(false)) compress();
        alchemize();
    }

    lld result = (lld)marble[1] + marble[2] * 2 + marble[3] * 3;
    cout << result;


    return 0;
}